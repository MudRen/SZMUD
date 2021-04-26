// Code of ShenZhou
// create by Karlopex@sz

#include <ansi.h>

inherit ITEM;
void create() {
        set_name("开封府门前的大鼓", ({ "da gu", "gu" }) );
        set_weight(2000000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一面大鼓，和其他的鼓没有区别。\n" );
	        set("no_get", 1);
		set("unit", "面");
                set("value", 10000000);
	}
        setup();
}

void init() {
        add_action("do_mingyuan", "ji");
        add_action("do_mingyuan", "qiao");
}

int do_mingyuan(string arg)
{
	object room, me = this_player(), here = environment(me);

        if ( wizardp(me) || me->query("age") < 20 )
                 return notify_fail("你鸣什么冤？别在这里捣乱！\n");

	if ( arg != "gu" && arg != "da gu")
		 return notify_fail("你要敲什么？\n");
	
	if ( me->query_temp("kff/jigu") < 2){
                me->add_temp("kff/jigu", 1);
		return 1;
	}
		
	shout(HIR"咚...咚...咚...，开封府门前"+(me->query("family/family_name")?me->query("family/family_name"):"普通百姓")
		+" "+me->name()+"("+getuid(me)+")"+HIR+"击鼓鸣冤！\n"NOR);

	message_vision(HIG"\n$N连击三通鼓，将鼓锤放回架子上，大步走进开封府大堂。\n" NOR, me);
	
	if ( !(room = find_object("/d/kaifeng/kaifengfu")) ) 
		room = load_object("/d/kaifeng/kaifengfu"); 

	me->move(room);
	me->delete_temp("kff/jigu", 1);
                me->set_temp("kff/my", "can");
	return 1;
}
	

