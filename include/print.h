#ifndef __PRINT_H_
#define __PRINT_H_

/*!
 * @brief	Display an error and quit fast.
 * @param	str	The format of the error to print.
 * @result	The error is printed and the program is immediately
 * 		terminated with an error exit code.
 * 		(atexit() methods are still run - use abort if you don't
 * 		like it.)
 */
void fatal(const char *str, ...);

/*!
 * @brief	Report an error condition to the user.
 * @param	str	The format of the error to print.
 */
void error(const char *str, ...);

/*!
 * @brief	Display information to the user.
 * @param	str	The format of the information to print.
 */
void info(const char *str, ...);

/*!
 * @brief	Display debug information to the user.
 * @param	str	The format of the information to print.
 * @note	This method is a no-op if NDEBUG is defined during
 * 		compilation.  Do not rely on this method for important
 * 		messages; use info instead.
 */
void debug(const char *str, ...);

#endif /*!__PRINT_H_*/