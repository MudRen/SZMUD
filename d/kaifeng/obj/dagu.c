// Code of ShenZhou
// create by Karlopex@sz

#include <ansi.h>

inherit ITEM;
void create() {
        set_name("���⸮��ǰ�Ĵ��", ({ "da gu", "gu" }) );
        set_weight(2000000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ���ģ��������Ĺ�û������\n" );
	        set("no_get", 1);
		set("unit", "��");
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
                 return notify_fail("����ʲôԩ���������ﵷ�ң�\n");

	if ( arg != "gu" && arg != "da gu")
		 return notify_fail("��Ҫ��ʲô��\n");
	
	if ( me->query_temp("kff/jigu") < 2){
                me->add_temp("kff/jigu", 1);
		return 1;
	}
		
	shout(HIR"��...��...��...�����⸮��ǰ"+(me->query("family/family_name")?me->query("family/family_name"):"��ͨ����")
		+" "+me->name()+"("+getuid(me)+")"+HIR+"������ԩ��\n"NOR);

	message_vision(HIG"\n$N������ͨ�ģ����Ĵ��Żؼ����ϣ����߽����⸮���á�\n" NOR, me);
	
	if ( !(room = find_object("/d/kaifeng/kaifengfu")) ) 
		room = load_object("/d/kaifeng/kaifengfu"); 

	me->move(room);
	me->delete_temp("kff/jigu", 1);
                me->set_temp("kff/my", "can");
	return 1;
}
	

