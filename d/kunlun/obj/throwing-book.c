// Code of ShenZhou
#include <ansi.h>

inherit ITEM;
//  inherit F_UNIQUE;
void create()
{
        set_name(WHT"投掷秘诀"NOR, ({"throwing book", "book"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是本昆仑暗器书，上面密密麻麻地记载了使用暗器的秘诀。。\n");
                set("material", "paper");
                set("value", 500);
        }
}
void init()
{
        add_action("do_study", "du");
        add_action("do_study", "study");
}
int do_study(string arg)
{
        object me = this_player();
        object ob = this_object();

        if (!id(arg)) return 0;

        if( !me->query_skill("literate", 1) ){
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }

        if (!present("throwing book", me)) return 0;
            if (!present("sangmen ding", me)){
          write("你要找到合适的武器才能比划。\n");
                 return 1;
          }

        if ( me->query("jing") < 35){
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }
        if (me->is_busy()) {
                write("你现在正忙着呢。\n");
                return 1;
        }
        if (environment(me)->query("pigging")){
                write("你还是专心拱猪吧！\n");
                return 1;
        }

        if ( me->is_fighting() ){ 
                write("你无法在战斗中专心下来研读新知！\n");
                return 1;
        }

        if ( me->query("potential") < 1){
                write("虽然你自觉潜能已经发挥到了极致，但是你沮丧上地发现还是没有学到任何东西！\n");
                return 1;
        }

        message("vision", me->name() + "对着《投掷秘诀》一阵乱比划。\n", environment(me), me);

        me->improve_skill("mantian-huayu", random(me->query_int()*3));
        me->receive_damage("jing", 800 / (int)me->query("int"));
//        me->add("potential", random(-1));

          if(me->query_skill("mantian-huayu", 1) > 180){
          me->add("potential", random(-1));
        me->receive_damage("jing", 1200 / (int)me->query("int"));
        }
        write("你比划了一会《投掷秘诀》，从中有所启发。\n");
        return 1;
}
