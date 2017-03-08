/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 04-03-2017
///		Date update	: 08-03-2017
///		Comment		:
/// ============================================================================
#include <QDir>

#include "treeview_filesystem.h"

namespace cfmc
{

namespace monitoring
{
/// ############################################################################
///			class treeview_filesystem
/// ############################################################################

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================

    /// ------------------------------------------------------------------------
    ///	treeview_filesystem( )
    /// ------------------------------------------------------------------------
    treeview_filesystem::treeview_filesystem(QWidget *parent) :
        QTreeView(parent)
    {
        this->initialize( );
    }
    /// ------------------------------------------------------------------------
    ///	~treeview_filesystem( )
    /// ------------------------------------------------------------------------
    treeview_filesystem::~treeview_filesystem( )
    {

    }

    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================

    /// ------------------------------------------------------------------------
    ///	path_root(const QString &path)
    /// ------------------------------------------------------------------------
    void treeview_filesystem::path_root(const QString &path)
    {
        if( this->_fs_model == nullptr )
        {
            return;
        }
        if( !QDir(path).exists( ) )
        {
            return;
        }
        this->_fs_model->setRootPath(path);
    }

    /// ------------------------------------------------------------------------
    ///	path_current( const QModelIndex &index )
    /// ------------------------------------------------------------------------
    QString treeview_filesystem::path_current( const QModelIndex &index ) const
    {
        if( ( this->_fs_model == nullptr )||( !index.isValid( ) ) )
        {
            return "";
        }

        return this->_fs_model->filePath( index );
    }

    /// ------------------------------------------------------------------------
    ///	path_current( )
    /// ------------------------------------------------------------------------
    QString treeview_filesystem::path_current( ) const
    {
        QModelIndex index = this->currentIndex( );

        return this->path_current( index );
    }

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================

    /// ------------------------------------------------------------------------
    ///	initialize( )
    /// ------------------------------------------------------------------------
    void treeview_filesystem::initialize( )
    {
        this->init_model( );

        this->init_connections( );

        this->select_home_path( );
    }

    /// ------------------------------------------------------------------------
    ///	init_model( )
    /// ------------------------------------------------------------------------
    void treeview_filesystem::init_model( )
    {
        this->_fs_model = new QFileSystemModel( );
        this->_fs_model->setReadOnly(true);
        this->_fs_model->setRootPath( QDir::root().absolutePath( ) );

        this->setModel( this->_fs_model );
    }

    /// ------------------------------------------------------------------------
    ///	init_connections( )
    /// ------------------------------------------------------------------------
    void treeview_filesystem::init_connections( )
    {
        connect(
                 this, &QTreeView::expanded,
                 this, &treeview_filesystem::resize_column_to_contents
               );
    }

    /// ------------------------------------------------------------------------
    ///	select_home_path( )
    /// ------------------------------------------------------------------------
    void treeview_filesystem::select_home_path( )
    {
        if( this->_fs_model == nullptr )
        {
            return;
        }

        QModelIndex index = this->_fs_model->index( QDir::homePath( ) );
        if( index.isValid() )
        {
            this->setCurrentIndex( index );
            this->expand( index );
        }
    }

    /// ========================================================================
    ///		SLOTS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    ///	resize_column_to_contents( )
    /// ------------------------------------------------------------------------
    void treeview_filesystem::resize_column_to_contents( )
    {
        this->resizeColumnToContents(0);
    }

}//namespace monitoring

}//namespace cfmc
