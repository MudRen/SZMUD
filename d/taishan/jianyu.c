// Code of ShenZhou
// Room: /d/shaolin/jianyu.c
// Date: lisser 2001/10/06

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "监狱");
	set("long", @LONG
这里黑沉沉的，即无一丝光亮，也无半分声息。黑暗中依稀
可以看到身边似乎有几个人影，看到你转过头去，他们立刻屏住
呼吸，紧张地瞪着你。四壁摸上去冰凉，且极硬，似乎都是钢铁
铸成，只有北面有一道小门，门上开了个巴掌大的洞，象是送饭
用的。脚边有一堆东西踢上去克剌剌地散了开来，细看却是一具
白得发亮的枯骨。
LONG
	);

        set("no_fight",1);
        set("no_get",1);
	set("valid_startroom",1);
	set("cost", 1);
	setup();

}
void reset()//make this room no refresh
{
        ::reset();
        set("no_clean_up", 1);
}
void init()
{       
	object ob = this_player();

        add_action("do_practice", "sleep");
        add_action("do_practice", "xiulian");
        add_action("do_practice", "lianneili");
        add_action("do_practice", "lianqi");

        if( (int)ob->query_condition("expell_c") <= 0 && !wizardp(ob))
	{
		message("vision",
			HIY "只听牢房铁门匡地一响，一个昏昏沉沉的家伙被扔了进来！\n\n" NOR, 
			environment(ob), ob);
		ob->set("startroom", "/d/taishan/jianyu");
                ob->apply_condition("expell_c", 960);
		ob->unconcious();
	}
}
int do_practice()

{
        write("歇会儿吧．．\n");
        return 1;
}
