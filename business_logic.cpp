/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 04-03-2017
///		Date update	: 11-03-2017
///		Comment		:
/// ============================================================================

#include <QApplication>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>

#include "business_logic.h"
#include "dir_csv_exporter.h"
#include "treeitem.h"

namespace cfmc
{

namespace monitoring
{

/// ############################################################################
///			class business_logic
/// ############################################################################

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    ///	choose_dir( )
    /// ------------------------------------------------------------------------
    list_fileinfo* business_logic::choose_dir( const QString &s_path, const QString &s_filter )
    {
        if( !QDir( s_path ).exists( ) )
        {
            return nullptr;
        }
        QString f_filter{s_filter};
        if( f_filter.isEmpty( ) )
        {
            f_filter = "*.*";
        }
        list_fileinfo *list = new list_fileinfo;
        business_logic::make_dir_info( list, nullptr, s_path, s_filter );

        return list;
    }

    /// ------------------------------------------------------------------------
    ///	export_data(const QString &s_path, const QString &s_filter)
    /// ------------------------------------------------------------------------
    void business_logic::export_data( const QString &s_path, const QString &s_filter )
    {
        QString f_filter{s_filter};
        if( f_filter.isEmpty( ) )
        {
            f_filter = "*.*";
        }
        dir_csv_exporter::export_path( s_path, f_filter );

        QMessageBox::information( nullptr, tr("info"), tr("finished") );
    }

    /// ------------------------------------------------------------------------
    ///	choose_dir( )
    /// ------------------------------------------------------------------------
    void business_logic::make_dir_info(
                                        list_fileinfo *list,
                                        TreeItem *diritem,
                                        const QString &s_path,
                                        const QString &s_filter
                                      )
    {
        QDir dir(s_path);
        QList<QVariant> data;
        data << dir.path( ) << 0 << 0;
        TreeItem *diritemchild = new TreeItem(data, diritem);

        QFileInfoList fi_dirs = dir.entryInfoList(
                                                   QDir::Dirs|QDir::NoDotAndDotDot,
                                                   QDir::Name
                                                 );

        for( QFileInfo fi : fi_dirs )
        {
            //for each dir...
            business_logic::make_dir_info( list, diritemchild, fi.filePath( ), s_filter );
        }
        //...count files and files size
        QStringList s_filters;
        s_filters << s_filter;
        QFileInfoList fi_files = dir.entryInfoList(
                                                    s_filters,
                                                    QDir::Files,
                                                    QDir::Name
                                                  );
        if( diritem == nullptr )
        {
            list->append(diritemchild);
        }
        else
        {
            diritem->appendChild(diritemchild);
        }

        qint32 f_count = fi_files.count( );
        if( !f_count )
        {
            return;
        }

        qint64 f_size = 0;
        for( QFileInfo fi : fi_files )
        {
            f_size += fi.size( );
        }
        diritemchild->item_data()[1] = f_count;
        diritemchild->item_data()[2] = f_size;
    }

}//namespace monitoring

}//namespace cfmc
