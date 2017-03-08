/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 04-03-2017
///		Date update	: 04-03-2017
///		Comment		:
/// ============================================================================
#ifndef __BUSINESS_LOGIC_H__
#define __BUSINESS_LOGIC_H__

#include <QObject>

namespace cfmc
{

namespace monitoring
{

/// ############################################################################
///			class business_logic
/// ############################################################################
    class business_logic : public QObject
    {
        Q_OBJECT
    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        business_logic( const business_logic &rhs );

    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================
        /// --------------------------------------------------------------------

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    public:
        /// --------------------------------------------------------------------
        static QString choose_dir( );
        /// --------------------------------------------------------------------
        static void export_data( const QString &s_path, const QString &s_filter );

    /// ========================================================================
    ///		OPERATORS
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        business_logic& operator=( const business_logic &rhs );

    /// ========================================================================
    ///			FIELDS
    /// ========================================================================
    private:

    };//class business_logic
/// ############################################################################
/// ----------------------------------------------------------------------------

}//namespace monitoring

}//namespace cfmc

#endif // __BUSINESS_LOGIC_H__
