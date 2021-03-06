        // Code of ShenZhou
// xiaoyuan.c 后山小院
// by Xiang
// Modified by xQin 11/00

inherit ROOM;
#include <room.h>
void create()
{
        set("short", "后山小院");
        set("long", @LONG
这是后山的一座小院，布置简简单单，除了一床、一桌、一椅、一蒲团
，再也没有别的什物。比较引人注目的是墙上挂着一把剑。这里就是武当开
山祖师张三丰的练功所在。后面有一本册子(ce)。
LONG
        );

        set("exits", ([
                "north" : __DIR__"hs_xiaolu",
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/zhang" : 1 ]));
        create_door("north", "竹门", "south", DOOR_CLOSED);
        set("cost", 1);
        setup();
}
void init()
{
        add_action("do_kill","kill");
                
                //Add by Scatter
                add_action("do_fan","fan");
                add_action("do_fan","flip");
}

int do_fan(string arg)
{
        if (arg != "ce")
        {
                return 1;
        }

        write("你看到这本书上写着\n");
        write("「真武七截阵」为张三丰所创，武当山一向供奉「真武大帝」。张三丰一日心血来潮，\n见到真武神像座前的龟蛇二将，想起长江和汉水之会的蛇山、龟山，心想长蛇灵动，乌龟凝重，\n真武大帝左右一龟一蛇，正是兼收至灵至重的两件物性，因而创了一套精妙无方的武功出来。\n这套武功便是从龟蛇二山大气磅礴，从山势演化出来的武功，森然万有，包罗极广。\n这套武功最大特色为若是七为高人合使，便如同六十四人高手合使一般，其威力之猛，\n实是无可比拟。\n\n这本书上看起来有点机关...\n\n");
        return 1;
}


int do_kill(string arg)
{
        object ob, ob1, me = this_player();

        if ( !arg || arg == "" ) return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;
        if ( !ob1=present("zhang sanfeng", environment(me)) ) return 0;
        if ( ob1 == ob ) return 0;
        if ( ob->query("family/family_name") == "武当派" ) {
                message_vision("$N一声冷笑：大胆狂徒！你也太小看老头子我了吧！\n ", ob1);
                ob1->kill_ob(me);
        }
        return 0;
}

