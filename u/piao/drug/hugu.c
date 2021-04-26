// Code of ShenZhou
// hugu.c ����

#include <ansi.h>

inherit ITEM;

int cure_ob(string);

void init();

void create()
{
	set_name("����", ({ "hu gu", "gu" }) );
        set_weight(1000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
	        set("unit", "֧");
                set("long", "����һ֧�ϻ����ֹǣ����Ǽ�Ϊ����ҩ�ġ�\n");
	        set("value", 1000);
	        set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
        me->add("food", 40);

        if ( (int)me->query_condition("bonze_drug" ) > 0 ){
                me->add("max_jingli", -1);
                me->add("eff_jingli", -1);
                me->set("jingli", 0);
                me->apply_condition("bonze_drug", 30);
                message_vision(HIR "$N����һ֧���ǣ�ֻ���øγ���ϣ��������ѣ�ԭ����ʳ̫��ҩ�ҩЧ�ʵ��䷴��\n" NOR, this_player());
              //  this_object()->move("/u/aln/workroom");
                call_out("destroy", 31);
                return 1;
        }

        if( !me->query_temp("cbs/hugu") ) {
                me->add_temp("apply/strength", 3);
                me->set_temp("cbs/hugu", 1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), me->query("con"));
        }

        me->receive_curing("qi", 200);
        me->set("qi", me->query("max_qi"));

        me->apply_condition("bonze_drug", 
        me->query_condition("bonze_drug")+30);
        message_vision(HIY "$N����һ֧���ǣ�ֻ����ȫ��ð����ˬ�����졣\n" NOR, me);
        //this_object()->move("/u/aln/workroom");
        call_out("destroy", 31);
        return 1;
}

void remove_effect(object me)
{
        me->add_temp("apply/strength", -3);
        me->delete_temp("cbs/hugu");
}

void destroy()
{
        destruct(this_object());
}
