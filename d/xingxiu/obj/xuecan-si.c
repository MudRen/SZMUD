// Code of ShenZhou
//By haowen  1/15/1999 

inherit ITEM;
#include <ansi.h>;
void create()
{
        set_name("ѩ��˿", ({"xuecan si", "can si","cansi"}));
        set_weight(80);
        set_max_encumbrance(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "����һ��ѩ��˿�������޺��Ե�ѩ������֮˿��ѩ������Զ�ϱ���ΪС��Ҳ�޶��ԣ�
�³����Ĳ�˿ȴ����������Ѱ����һ����˿���Ѳ������ϡ�\n");
                set("unit", "��");
                set("value", 0);
                set("busy_source", random(5)+1);
        }
}
void init()
{
        add_action("do_shou", "shou");
        add_action("do_shou", "catch");
//        add_action("do_fang", "fang");
//	add_action("do_fang", "release");
}
int do_shou(string arg)
{
        object  env,*inv,target,ob,me=this_player();
	int i;
	ob=this_object();
	env=environment(me);
	inv=all_inventory(env);
	for (i=0;i<sizeof(inv);i++){
		if (inv[i]==me) continue;
		if(!me->visible(inv[i])) continue;
		if (inv[i]->query("id")==arg)
			target=inv[i];
		}
        if (!target) 
		return notify_fail("������˭��\n");
        
	if(target==me)
		return notify_fail("�㲻�����Լ���\n");

//	if(!userp(target))
//		return notify_fail("��ֻ������ң�\n");
	
        if(!me->is_fighting() || !target->is_fighting() || !living(target))
                return notify_fail("�������ս���в���ʹ��ѩ��˿��\n");

        if(me->query_skill("feixing-shu",1)<30)
		return notify_fail("�������ڵİ������������ò���ѩ��˿��\n");

	if(me->is_busy())
		return notify_fail("�������޷����κζ�����\n");

	if(target->is_busy())
		return notify_fail(target->query("name")+"���Թ˲�Ͼ�����ֹ����ɣ�\n");
   
        message_vision( HIY "$N��Ц�����������ƺ���ʲô������$n��ȥ��\n" NOR,me,target);
        if(random(me->query_skill("feixing-shu",1)) > random(target->query_skill("dodge",1)))
		{
		 tell_object(target,HIR "���Ȼ����һ��ϸ�߲���ȫ���ֽŶ��Ѿ����ܿ��ƣ�\n" NOR);
		 tell_object(me,HIG "������һ�������а�ϲ�������Ѿ������ˣ�\n" NOR);
		 target->start_busy(ob->query("busy_source"));
//                 me->start_busy(1);
                }
	else {
		message_vision(HIY "$n����һԾ���ܿ���$N���еĶ�����\n" NOR,me,target);
                tell_object(me,HIG "��Ͻ�����һ�ۣ��ջ���ѩ��˿��\n" NOR);
                me->start_busy(2);
	     }		
	me->add("neili",-50);
	return 1;
}

