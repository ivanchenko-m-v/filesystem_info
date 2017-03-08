/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 04-03-2017
///		Date update	: 08-03-2017
///		Comment		:
/// ============================================================================

#include <QApplication>
#include <QVBoxLayout>
#include <QMessageBox>

#include "mainwindow.h"
#include "business_logic.h"

namespace cfmc
{

namespace monitoring
{
/// ############################################################################
///			class main_window
/// ############################################################################

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================

    /// ------------------------------------------------------------------------
    ///	main_window( )
    /// ------------------------------------------------------------------------
    main_window::main_window(QWidget *parent) :
        QMainWindow(parent)
    {
        this->initialize( );
    }
    /// ------------------------------------------------------------------------
    ///	~main_window( )
    /// ------------------------------------------------------------------------
    main_window::~main_window( )
    {

    }
    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================

    /// ------------------------------------------------------------------------
    ///	initialize( )
    /// ------------------------------------------------------------------------
    void main_window::initialize( )
    {
        this->init_geometry( );

        this->init_layout( );

        this->init_actions( );
    }

    /// ------------------------------------------------------------------------
    ///	init_geometry( )
    /// ------------------------------------------------------------------------
    void main_window::init_geometry( )
    {
        this->setMinimumWidth( this->_MIN_WINDOW_WIDTH );
        this->setMinimumHeight( this->_MIN_WINDOW_HEIGHT );
    }

    /// ------------------------------------------------------------------------
    ///	init_layout( )
    /// ------------------------------------------------------------------------
    void main_window::init_layout( )
    {
        QWidget *widget = new QWidget( this );

        QVBoxLayout *layout = new QVBoxLayout;
        //
        //_fs_tree
        //
        layout->addWidget( this->init_fs_tree( ), this->_STRETCH_TREE_ );
        //
        //_lv_fileinfo
        //
        layout->addWidget( this->init_lv_fileinfo( ), this->_STRETCH_LIST_ );
        //
        //_pn_buttons
        //
        layout->addWidget( this->init_pn_buttons( ), this->_STRETCH_BUTTONS_ );

        widget->setLayout(layout);
        this->setCentralWidget( widget );
    }

    /// ------------------------------------------------------------------------
    ///	init_actions( )
    /// ------------------------------------------------------------------------
    void main_window::init_actions( )
    {
        //
        //panel_buttons::export_data
        //
        QObject::connect(
                        this->_pn_buttons, &panel_buttons::export_data,
                        this, &main_window::export_data
                        );
        //
        //panel_buttons::choose_dir
        //
        QObject::connect(
                        this->_pn_buttons, &panel_buttons::choose_dir,
                        this, &main_window::choose_dir
                        );
        //
        //panel_buttons::exit_app
        //
        QObject::connect(
                        this->_pn_buttons, &panel_buttons::exit_app,
                        QApplication::instance(), &QApplication::quit
                        );
    }

    /// ------------------------------------------------------------------------
    ///	init_fs_tree( )
    /// ------------------------------------------------------------------------
    QWidget* main_window::init_fs_tree()
    {
        this->_fs_tree = new treeview_filesystem(this);
        return this->_fs_tree;
    }

    /// ------------------------------------------------------------------------
    ///	init_lv_fileinfo( )
    /// ------------------------------------------------------------------------
    QWidget *main_window::init_lv_fileinfo( )
    {
        this->_lv_fileinfo = new listwidget_files_info(this);
        return this->_lv_fileinfo;
    }

    /// ------------------------------------------------------------------------
    ///	init_pn_buttons( )
    /// ------------------------------------------------------------------------
    QWidget* main_window::init_pn_buttons( )
    {
        this->_pn_buttons = new panel_buttons(this);
        return this->_pn_buttons;
    }

    /// ========================================================================
    ///		SLOTS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    ///	choose_dir( )
    /// ------------------------------------------------------------------------
    void main_window::choose_dir( )
    {
        const QString& s_path = this->_fs_tree->path_current( this->_fs_tree->currentIndex( ) );
        QMessageBox::information(
                                nullptr, tr("info"),
                                s_path
                    );
    }

    /// ------------------------------------------------------------------------
    ///	export_data( )
    /// ------------------------------------------------------------------------
    void main_window::export_data( )
    {
        business_logic::export_data(
                                    this->_fs_tree->path_current( ),
                                    this->_pn_buttons->files_filter( )
                                   );
    }

}//namespace monitoring

}//namespace cfmc
