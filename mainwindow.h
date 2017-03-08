/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 04-03-2017
///		Date update	: 08-03-2017
///		Comment		:
/// ============================================================================
#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>

#include "treeview_filesystem.h"
#include "listwidget_files_info.h"
#include "panel_buttons.h"

namespace cfmc
{

namespace monitoring
{

/// ############################################################################
///			class main_window
/// ############################################################################
    class main_window : public QMainWindow
    {
        Q_OBJECT
    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        main_window( const main_window &rhs );

    public:
        /// --------------------------------------------------------------------
        explicit main_window(QWidget *parent = 0);
        /// --------------------------------------------------------------------
        virtual ~main_window( );

    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================
        /// --------------------------------------------------------------------

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        void initialize( );
        void init_geometry( );
        void init_layout( );
        void init_actions( );
        QWidget* init_fs_tree( );
        QWidget* init_lv_fileinfo( );
        QWidget* init_pn_buttons( );

    /// ========================================================================
    ///		OPERATORS
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        main_window& operator=( const main_window &rhs );

    /// ========================================================================
    ///		SLOTS
    /// ========================================================================
    private:
        void choose_dir( );
        void export_data( );

    /// ========================================================================
    ///			FIELDS
    /// ========================================================================
    private:
        const int _MIN_WINDOW_WIDTH = 1024;
        const int _MIN_WINDOW_HEIGHT = 768;

        const int _STRETCH_TREE_ = 1000;
        const int _STRETCH_LIST_ = 1000;
        const int _STRETCH_BUTTONS_ = 1;

        treeview_filesystem *_fs_tree = nullptr;
        listwidget_files_info *_lv_fileinfo = nullptr;
        panel_buttons *_pn_buttons = nullptr;

    };//class main_window
/// ############################################################################
/// ----------------------------------------------------------------------------

}//namespace monitoring

}//namespace cfmc

#endif // __MAINWINDOW_H__
