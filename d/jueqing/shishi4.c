// Filename:   /d/jueqinggu/shishi4.c ʯ��4
// by Jiuer 08/15/2001


inherit ROOM;

void create()
{
		  set("short","ʯ��");
		  set("long",@LONG
���Ǽ����������ʯ�ң�ƽʱ��Ѻ���˵ĵط���ǽ����Щ���ҵĿ�
����������Ƭ�ò�ϯ�����϶���Щ�鼦��ͷ�������һ������Ѵ���
�죬�ȵô���������
LONG);

		  set("no_fight",1);
		  set("cost",3);
		  setup();	
}

void init()
{
	add_action("do_break","break");  
}

int do_break(string arg)          
{
	object weapon, me = this_player();

	if( !arg || arg != "wall")					
		return notify_fail("�����ʲô�� \n");
	
//���������Ŀ��
	if(!objectp(weapon = me->query_temp("weapon"))    
		|| (string)weapon->query("skill_type") != "sword")
	{
		message_vision(
			"$N��������֮������׼ǽ���ͻ���ȥ��\n", me);
		message_vision(
			"���ʯ��δ�ƣ�$N�Լ������������𣬶�ʱһ����Ѫ��ڶ�����\n", me);
		me->add("neili",-200);
		me->receive_damage("qi",200,"����͸֧��������");
	}
	else {        //with weapon and break wall;
		if((int)me->query("neili")>=200)  //������������������
		{
			message_vision("$N�������������һ�����ӽ���׼ǽ�����˹�ȥ��\n",me);
			message_vision("ǽ�϶�ʱ������һ���󶴡�\n",me);			
			set("exits/out",__DIR__"huowanshi");
			me->add("neili", -200);	// ��������200��
			remove_call_out("close_door");
			call_out("close_door", 10,me);
}
		else														//������������������
		{
			message_vision("$N����̫�����������ģ�����������ˣ�һ����Ѫ��ڶ�����\n",me);
			me->set("neili",0);
			me->receive_damage("qi",200, "����͸֧��������");

			destruct(weapon);
		}

		return 1;
	}
	
	return 1;
}

void close_door()
{
	tell_room(this_object(),"����Ĺ��˺ܿ������ש��ǽ������! \n");
	delete("exits/out");
}