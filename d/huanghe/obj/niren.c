/* /d/huanghe/obj/niren.c
** ʮ������ 
** created by yujie 
** created in 1/2002 
*/ 

#include <ansi.h> 
  
inherit ITEM; 

      
void create() 
{ 
	set_name(CYN"������ż"NOR, ({ "niren wanou", "niren" }) ); 
	set_weight(10); 
	set("unit", "��"); 
	set("long", "����һ�����Ƶ���ż��\n����ľ������е����޻����������������ˡ�\nÿ������������һʮ�˸���\n��ż�������ɣ�ÿ��������������ˣ�Ƥ����Ϳ�˰��ѣ�������һ�������ߣ����������ڵ㣬���������Ѩ���ķ�λ��\n"); 
	set("value", 0); 
	set("material", "wood"); 
	set("no_drop", "�������صĶ�����ô������Ҷ��ء�\n"); 
	set("no_get", "�������������뿪�Ƕ���\n"); 
	set("broken",0);

	setup();
}

void init()
{
	add_action("do_break","break");
}

int do_break(string arg)
{	
	object me=this_player();
	object ob=this_object();
	
	if (arg != "niren wanou" && arg != "niren")
		return notify_fail("��Ҫ����ʲô��\n");
		
	if ( query("broken")==1 )	
		return notify_fail("���������Ѿ���������ˡ�\n");
		
	message_vision(HIW"$N�˾���������һ�󡣡���\n"NOR+HIG"ֻ��ˢˢˢ������������������ķ��Ρ��Ͳʺ���׷׷׵��䡣\n����������䣬����¶��һ�������ľ�档\n$N�����ٽ���۰���һЩ��������ϡ�ֳ����Σ�����$N����������������۾�����ȥ��¶��һ���������ľż����\nľż�������ϲ�ò�������ʹ�����ᣬ��������ŭ����ȺͿ��ף���һ��ͬ��\nľż���ϵ��˹���·��Ҳ��������������ȫȻ���졣\n"NOR,me);

	set("broken",1);
	set_name(YEL"ľż"NOR, ({ "mu ou", "muou" }) ); 
	set("long","����һ�������в��ŵ�ľż��\n������������һ��ͩ�ͣ������˺��ߣ�ȴ��Ѩ��λ�á�\nľż�̹����ɣ���Ŀ������������������Ц֮״��˫����������̬����֮������ò�ͱ��������˽�Ȼ��ͬ��\nľż������Ƶ��˹���·��������������Գ������������ϵ���·��������liangong������\n");
		
	add_action("do_liangong","liangong");
	return 1;
}

int do_liangong(string arg)
{
	object me=this_player();
	object ob=this_object();
	int step=0;
	
        if(me->is_busy() )
		return notify_fail("����æ���ء�\n"); 

	if ( me->query("neili")<1000)
		return notify_fail("�������������㣬�޷�����������·����������\n");
		
        if ( me->query_skill("force",1) > 299)
		return notify_fail("����ڹ����д�ɣ�����Ҫ�ٰ���ľż�ϵķ�ʽ���������ˡ�\n");
		
        message_vision("$N������ϥ��������ľż������ǰ��������΢΢����������һ��ů�������Ϣ����������\n$N����ľż����������·��������Ϣͨ�����Ѩ����\n",me);
	
	remove_call_out("doing");
          call_out("doing", 10, 0 , me); 
	me->start_busy(10);
	return 1;
}

int doing(int step, object me)
{
        switch (step)
	{
        case 0 : message_vision("$N��������ˮ����ã��������ϣ���Ȼʮ����񣬽������������ľ�޺�������·���У�һ�����ʹ��޲���Ȼ���⡣\n",me);break;
	case 1 :
                message_vision("$N������·�������飬Ȼ������۾�������ľż���˹���ֻ���泩֮���������ֻ���һ��ľż������\n",me);
		break;
    
    	case 2 :
                message_vision("$Nȫ��ȫ��ĳ������У�����һ��ľż������һ������������ȫȻ�Ĳ��Ų�����\n",me);
		break;
		
	case 3 :
                message_vision("$N����������ʮ����ľ�޺������������·�����������˿�������ľż������У����Ϻиǣ�ֻ��������ˬ��������ת���޲����⣬\n",me);
                me->improve_skill( "force",me->query("con")*60 ); 
                me->add("neili",-500-random(300)); 
		break;
	}
	
        if ( step < 3)
	{	step++;
		remove_call_out("doing");
		call_out("doing",10,step,me);
		me->start_busy(10);
	}
	
        return 1;
}
		

