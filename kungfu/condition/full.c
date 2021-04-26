#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    me->apply_condition("full", duration);
    if ( me->query( "neili" ) < me->query( "max_neili" )*3/2 );
        me->set("neili", 2*me->query("max_neili"));
    if ( me->query( "jingli" ) < me->query( "max_jingli" )*3/2 );
        me->set("jingli", 2*me->query("max_jingli"));
    if ( me->query( "jing" ) < me->query( "max_jing" )/2 )
        me->set( "jing", me->query( "max_jing" ) );
    me->add( "combat_exp", 20+random(20) );
    me->improve_skill( "force", 20+random( 30 ) );
    me->improve_skill( "literate", 20+random(20) );
    return 1;
}

