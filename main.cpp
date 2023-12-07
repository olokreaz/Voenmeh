#include <fmt/core.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <ranges>

template < > struct fmt::formatter< glm::i8vec2 >
{
	template < typename ParseContext > constexpr auto parse( ParseContext &ctx ) { return ctx.begin( ); }
	
	template < typename FormatContext > auto format( const glm::i8vec2 &vec, FormatContext &ctx )
	{
		return fmt::format_to( ctx.out( ), "{{{}, {}}}", vec[ 0 ], vec[ 1 ] );
	}
};

using vec_t = glm::i8vec2;
using result_t = glm::i8vec4;
using glm::i8, glm::u8;

enum class SignedMask : glm::i8
{
	kSign = 0b00100000, kMask = 0b00111111
};

u8 getLineCode( i8 x )
{
	if ( x == 0 ) return 0;
	return x < 0 ? ( glm::abs( x ) | ( i8 ) SignedMask::kSign ) & ( i8 ) SignedMask::kMask : x;
}

// -5 -> 0b010 <- reverse
u8 getReversCode( i8 x )
{
	if ( x == 0 ) return 0;
	return ( glm::sign( x ) ? ~ glm::abs( x ) : x ) & ( i8 ) SignedMask::kMask;
}

u8 getMoreCode( i8 x )
{
	return x & ( i8 ) SignedMask::kMask;
}

int main( int, char ** )
{
	std::vector< vec_t > data { { 17,   5 },
	                            { - 9,  16 },
	                            { - 8,  - 27 },
	                            { - 25, - 25 },
	                            { 16,   - 14 },
	                            { - 8,  - 21 } }; // <--- Это поменять под ваше задание
				    
				    if (__argc > 1)
				    {
					    data.clear();
					    data.push_back({std::atoi(__argv[1]), std::atoi(__argv[2])});
				    }
				    
	std::vector< result_t >                                           result;
	for ( const auto                                                  &vec : data )
		{
			result_t r { vec.x, vec.y, vec.x + vec.y, vec.x - vec.y };\
                        result.push_back( r );
		}
	
	const std::unordered_map< std::string, std::function< u8( i8 ) >> mp { { "line",    &getLineCode },
	                                                                       { "reverse", &getReversCode },
	                                                                       { "more",    &getMoreCode } };
	
	for ( const auto &vec : result )
		{
			fmt::println( "{}", vec_t( vec ) );
			for ( const auto &[ key, func ] : mp )
				{
					fmt::println( "{}", key );
					fmt::println( "x {:d} : {:06b}", vec[ 0 ], func( vec[ 0 ] ) );
					fmt::println( "y {:d} : {:06b}", vec[ 1 ], func( vec[ 1 ] ) );
					fmt::println( "-y {:d} : {:06b}", - vec[ 1 ], func( - vec[ 1 ] ) );
					fmt::println( "x+y {:d} : {:06b}", vec[ 2 ], func( vec[ 2 ] ) );
					fmt::println( "x-y {:d} : {:06b}", vec[ 3 ], func( vec[ 3 ] ) );
					fmt::println( "" );
				}
		}
	
	
	return 0;
}