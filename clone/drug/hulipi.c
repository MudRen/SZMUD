// Code of ShenZhou
// hulipi.c ����Ƥ

#include <ansi.h>

inherit ITEM;

int cure_ob(string);

void init();

void create()
{
	set_name("����Ƥ", ({ "huli pi", "pi" }) );
        set_weight(1000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
	        set("unit", "��");
                set("long", "����һ��ë����������⻬�ĺ���Ƥ��\n");
	        set("value", 3000);
                set("no_sell", 1);
	        set("medicine", 1);
	}

	setup();
}

int cure_ob(object me)
{
        me->add("food", 30);

        if ( (int)me->query_condition("bonze_drug" ) > 0 ){
                me->add("max_jingli", -1);
                me->add("eff_jingli", -1);
                me->set("jingli", 0);
                me->apply_condition("bonze_drug", 30);
                message_vision(HIR "$N����һ�ź���Ƥ��ֻ���øγ���ϣ��������ѣ�ԭ����ʳ̫��ҩ�ҩЧ�ʵ��䷴��\n" NOR, this_player());
               // this_object()->move("/u/aln/workroom");
                call_out("destroy", 31);
                return 1;
        }

        if( !me->query_temp("cbs/hulipi") ) {
                me->add_temp("apply/dexerity", 3);
                me->set_temp("cbs/hulipi", 1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), me->query("con"));
        }

        me->add("jingli", 300);
        me->apply_condition("bonze_drug", 
        me->query_condition("bonze_drug")+30);
        message_vision(HIY "$N����һ�ź���Ƥ��ֻ��ȫ��ľ������ָ��ˡ�\n" NOR, me);
        call_out("destroy", 31);
        return 1;
}

void remove_effect(object me)
{
        me->add_temp("apply/dexerity", -3);
        me->delete_temp("cbs/hulipi");
}

void destroy()
{
        destruct(this_object());
}

