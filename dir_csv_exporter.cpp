/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 08-03-2017
///		Date update	: 11-03-2017
///		Comment		:
/// ============================================================================
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QFileInfo>
#include <QFileInfoList>

#include "dir_csv_exporter.h"

namespace cfmc
{

namespace monitoring
{

/// ############################################################################
///			class dir_csv_exporter
/// ############################################################################

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    ///	export_path(const QString &s_path, const QString &s_filter)
    /// ------------------------------------------------------------------------
    void dir_csv_exporter::export_path( const QString &s_path, const QString &s_filter )
    {
        if( !QDir( s_path ).exists( ) )
        {
            return;
        }

        QFile data( "output.csv" );
        if( data.open( QFile::WriteOnly | QFile::Truncate ) )
        {
            QTextStream out( &data );
            out.setCodec( "UTF-8" );

            //output header info to file
            out << QObject::tr("Parent folder:") << ";"
                << QObject::tr("Folder:") << ";"
                << QObject::tr("File type:") << ";"
                << QObject::tr("Count:") << ";"
                << QObject::tr("Size:") << endl;

            //output info to file
            dir_csv_exporter::process_dir( s_path, s_filter, out );
        }
        data.close( );
    }

    /// ------------------------------------------------------------------------
    ///	process_dir( const QString &s_path, const QString &s_filter, QTextStream &out )
    /// ------------------------------------------------------------------------
    void dir_csv_exporter::process_dir(
                                        const QString &s_path,
                                        const QString &s_filter,
                                        QTextStream &out
                                      )
    {
        QDir dir( s_path );
        QFileInfoList fi_dirs = dir.entryInfoList(
                                                   QDir::Dirs|QDir::NoDotAndDotDot,
                                                   QDir::Name
                                                 );

        for( QFileInfo fi : fi_dirs )
        {
            //for each dir...
            dir_csv_exporter::process_dir( fi.filePath( ), s_filter, out );
        }
        //...count files and files size
        dir_csv_exporter::process_dir_files( dir, s_filter, out );
    }

    /// ------------------------------------------------------------------------
    ///	process_dir( const QDir &dir, const QString &s_filter,  QTextStream &out )
    /// ------------------------------------------------------------------------
    void dir_csv_exporter::process_dir_files( const QDir &dir, const QString &s_filter,  QTextStream &out )
    {
        QStringList s_filters;
        s_filters << s_filter;
        QFileInfoList fi_files = dir.entryInfoList(
                                                    s_filters,
                                                    QDir::Files,
                                                    QDir::Name
                                                  );
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

        //output header info to file
        out << dir_csv_exporter::dir_parent_path( dir ) << ";"
            << dir.path( ) << ";"
            << s_filter << ";"
            << QString::number( f_count ) << ";"
            << QString::number( f_size ) << endl;
    }

    /// ------------------------------------------------------------------------
    ///	dir_parent_path( const QDir &dir )
    /// ------------------------------------------------------------------------
    QString dir_csv_exporter::dir_parent_path( const QDir &dir )
    {
        QDir dir_parent( dir );
        QString s_dir_parent = "";

        if( dir_parent.cdUp( ) )
        {
            s_dir_parent = dir_parent.path( );
        }

        return s_dir_parent;
    }

}//namespace monitoring

}//namespace cfmc
