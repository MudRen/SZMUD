// /d/city/ftb_mishi.c
//Alan.F 20010927
#include "room.h"
#include "ansi.h"

int do_break(string);


inherit ROOM;

void create()
{
        set("short", "密室");
        set("long", @LONG
这里是斧头帮的一间密室，墙上挂着一盏油灯，中间摆着个香案，供奉着一
人的灵位（lingwei）和一封信(letter)，仔细一看上面写着袁崇焕。原来这里是
枉死的爱国忠臣的灵位，没想到斧头帮竟如此敬重爱国将领。香案的下面是一只大
箱子（xiangzi）,锁都已经锈的打不开的。
LONG
        );
        set("exits", ([
                "up" : __DIR__"minwu1",
        ]));
        set("cost", 1);
        set("invalid_startroom", 1);
        
	set("item_desc", ([
		"lingwei": "袁崇焕忠烈位\n",
		"letter": "此乃袁将军遗物，多年来为斧头帮带来多少江湖风波，壮士为斧头帮尽心尽力，今一次相增，廖表寸心\n",
		"xiangzi": "一个大箱子，锁已经坏了，不过你可以试试撬开（break）\n",
	]));
        
        
        setup();
}
        
void init()
{
        add_action("do_break","break");
}

int do_break(string arg)
{
    int qi,max_qi;
    object me = this_player();
    object gold,jian;
    max_qi = me->query("max_qi");
    qi = me->query("qi");


    if( !arg || arg!="xiangzi" ) {
        write("不要随便打碎别人的东西！\n");
        return 1;
    }

if (me->query("mishi")){

    message_vision(
    "$N用力朝箱子踢了一脚。\n", me);
        
        message_vision(
        "只听一声轰响，$N把箱子给踹散了架！\n", me);
        tell_object(me,HIR "金银珠宝散了一地。\n" NOR);
        me->set("max_qi",max_qi-1);
//        jian = new ("/clone/unique/bixue-jian");
        gold = new("/clone/money/gold");
        gold->set_amount(100);
//        jian -> move(me);
        gold -> move(me);
        tell_object(me,HIR "你慌忙趴了上去，牙都碰掉了一颗，生怕别人抢你的。\n" NOR);
        tell_object(me,HIY "你了收起一大堆黄金！\n" NOR);
//        tell_object(me,RED "并有一柄剑！\n" NOR);
        me->delete("mishi");
  }
  else {
        message_vision(
        "$N用力朝箱子踢了一脚,结果腿断了。\n", me);
        me->set("max_qi",max_qi-10);
        me->set("qi",qi-100);
        
    }
    return 1;

  }
