// Code of ShenZhou
// /d/changbai/renshen.c �˲�

inherit ITEM;
#include <ansi.h>
void setup()
{}

int cure_ob(string);

void create()
{
        set_name("�˲�", ({"ren shen", "shen"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��մ��ɽ��ĳ���ɽ�˲Ρ�\n");
                set("value", 1000);
                set("medicine", 1);
        }
        setup();
}

int cure_ob(object me)
{
        if ( (int)me->query_condition("bonze_drug" ) > 0 ) {
                me->add("eff_jingli", -1);
                me->add("max_jingli", -1);
                message_vision(HIR "$N����һ���˲Σ�ֻ����ͷ�ؽ��ᣬ�������ڣ�ԭ����ʳ̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
                this_object()->move("/u/aln/workroom");
                call_out("destroy", 31);
                return 1;
        }

        if( !me->query_temp("cbs/renshen") ) {
                me->add_temp("apply/constitution", 5);
                me->set_temp("cbs/renshen", 1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), me->query("con"));
        }

        me->add("jingli", 150);
        me->add("neili", 150);

        message_vision(HIG"$N����һ���˲Σ�ֻ���û���һ����������ð������ !\n" NOR, me);

        me->apply_condition("bonze_drug", 
                this_player()->query_condition("bonze_drug")+30);

        this_object()->move("/u/aln/workroom");
        call_out("destroy", 31);
        return 1;
}

void remove_effect(object me)
{
        me->add_temp("apply/damage", -30);
        me->delete_temp("cbs/renshen");
}

void destroy()
{
        destruct(this_object());
}

