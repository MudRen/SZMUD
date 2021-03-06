#include <ansi.h>
 
inherit ITEM;
 
void create()
{
    set_name(RED BCYN "碧玉珠" NOR, ({"biyu dan", "dan"}));
    set_weight(20);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "颗");
        set("value", 100000);
        set( "long", HIW"这是一颗晶莹剔透的小珠子，洁白、透明的珠身中含着一点绿痕。\n"
                +"据传此珠只有在万古寒冰之中才可产生。\n"NOR );
        set("medicine", 1);
    }
 
    setup();
}
 
int feed_ob(object ob)
{
    int lever = 0;
    lever = ob->query_skill( "beauty", 1 );
    if ( ob->query( "gender" ) == "男性" )
    {
        message_vision( "$N吃下一颗碧玉珠，可是由于体性不合，脸上如雨后春笋般的冒出许多红点。\n", ob );
        ob->add( "per", -1 );
        destruct(this_object());
    return 1;
    }    
    if ( ob->query( "gender" ) != "女性" )
    {
        message_vision( "$N吃下一颗碧玉珠，只是觉得很好吃。\n", ob );
        destruct(this_object());
    return 1;
    }    
    if ( ob->query( "beautydan", 0 ) )
    {
        lever = lever - 50;
        if ( lever < 1 )
            lever = 1;
        message_vision( "$N又吃下一颗碧玉珠，由于服食过多，又恢复了以前的容貌。\n", ob );
        ob->set_skill( "beauty", lever );
        ob->add( "per", -1 );
        ob->delete( "beautydan" );
        destruct(this_object());
    return 1;
    }            
    lever = lever + 50;
    ob->set_skill( "beauty", lever );
    ob->add( "per", 1 );
    message_vision("$N轻轻将碧玉珠含入嘴中，只觉一丝极冰极冷的冰丝沿中腑、气海、丹田、命门\n"
            + "大椎、百会飞速流转。片刻，这清凉感觉遍布全身，你觉得双目似润润有物，青丝微动，\n"
            + "你感觉$N的容貌好像发生了变化。 \n",ob );
    log_file("beauty", ob->name() + "(" + ob->query("id") 
            + ") eat a beauty dan at " + ctime(time()) + "\n");
    ob->set( "beautydan", 1 );
    destruct(this_object());
    return 1;
}
 
