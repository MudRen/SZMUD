/*-------------------------------------------------------------
** 文件名: car.c
** Copyright (c) 2000-2001
** 创建人: 武馆工作组
** 日  期: 2001/08/13
** 描  述: 大车
**-----------------------------------------------------------*/

#include <ansi.h>
inherit ITEM;

void arrive(object, object, object, string, string, string);
int do_hire(string arg);

void create()
{
        set_name(HIY"武馆大车"NOR, ({ "wuguan dache", "dache", "carriage"}) );
	set_weight(500000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
	else {
		set("unit", "乘");
        	set("long", @LONG
这是一乘由两匹马拉着的大车。大车前面坐着一个老车夫，手里握着
只长鞭。他嘴里不停着哼哼着什么，心不在焉地四周望着。

车夫见你来了，迎上来说道：这车是扬威武馆包下来的。你想
去(qu)哪我都可以载你去，扬州，杭州，泉州，泰山，少林，神龙
塘沽口，武当，峨嵋，大理，西夏，华山，星宿，雪山，兰州，佛
山，终南山，还是新开的古墓？
LONG
	);
		set("value", 1000000);
		set("material", "steel");
		set("no_get",1);
	}
	setup();
}