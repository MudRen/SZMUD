//                ��׼��������ʾ��                                   |
// �κεĶĳ�����  ��dc_dating.c
// by naihe  2002-05-20  ��ï��
// �ĳ�����Ϸ���ʾ������ϸ���ԣ��޸ı��ļ����ʵȴ��������أ�
// �ĳ�ȫ�¸İ�  :)

#include <ansi.h>
#include <room.h>
inherit ROOM;

string look_pai();
int totalplay,totalbet,totalwin;

void create()
{
	set("short", HIY"�ĳ�����"NOR);
	set("long", "�����Ƕĳ��Ĵ������ſ���һ���ɰ���С�������ڲ��ϵغͽ����Ŀ��˴���
������������ڷ����ų�һȦ����ಿ����Ļ�����jiqi����ֻ�������ǡ��ס���
�������ز��Ϸ���������������������Ŀմ���һ�� ATM��Ա������˵������
�Ļ�����ʹ����ʱ������Ǯׯ��һ�����㡣���������м���Сͨ�������ߵ�ͨ��
������������������Ϸ��������������С�������ǹ����������λ���м���
С���䣬�����ǿ��Ե�����ȥ��ĳ���������Ϸ�����ϱ���һ��ϴ�ּ䣬��˵��
�����˾Ͱ�ȥϴ����תת��������Ի��ϴ˥����Ҳ��֪�����Ǽ١�¥����һ����
����Ĳ����������������˶�����ȥ�Ե㶫������Ϣһ�ᡣֻ�����������ŵ�
ǽ������Ŀ�Ĺ���һ��С���ӣ�paizi����\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up","1");
	set("invalid_startroom",1);

	set("item_desc",([
	    "paizi": (: look_pai :),
	    "jiqi":"ÿ��1-50������������(bet <��/С> <����>)������Ϸ��4-10ΪС��11-17Ϊ��\n������û�а������лƽ�ʱ���������Զ����㣬��ֱ����Ϸ���ɡ�\n",
	]));

	set("objects", ([
	    __DIR__"npc/atm" : 1,
	    __DIR__"obj/yizi" : 1,
	    ]));

	set("exits", ([
	    "east": __DIR__"dc_horse",
            "west":__DIR__"dc_kill",
	    "southwest":__DIR__"dc_lav",
	    "vip":__DIR__"dc_vip",
	    "up":__DIR__"dc_chazuo",
	    "out":__DIR__"dc_door",
	    "adj":__DIR__"adj",
	    "bdj":__DIR__"bdj",
	    "cdj":__DIR__"cdj",
	    ]));

	create_door("vip", "С��", "out", DOOR_CLOSED);

// �������board��Ҫ��clone�Ǳߵ�Ŀ¼����Ӧ��Ӳ��С�
	setup();
	call_other("/clone/board/duchang_b","???");
}

void init()
{
	if (wizardp(this_player()))  add_action("do_xxx", "xxx"); // wiz ���Բ�ѯ��ֵ��
	add_action("do_skills",  "exercise");
	add_action("do_skills",  "dazuo");
	add_action("do_skills",  "respirate");
	add_action("do_skills",  "tuna");
	add_action("do_skills",  "practice");
	add_action("do_skills",  "lian");
	add_action("do_study",  "study");
	add_action("do_study",  "du");
//        add_action("do_outhere", "out");
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_food", "drink");
	add_action("do_food", "he");
	add_action("do_bet","bet");
}

  void reset() 
  { 
                ::reset(); 
                set("no_clean_up", 1); 
  } 

string look_pai()
{
	if(wizardp(this_player())) write("��ʦ������<xxx>ָ��鿴���ڵ���Ϸͳ�ơ�\n");
	return "���������֣���Ӯ������\n";
}

int do_xxx()
{
	int temp =(totalbet-totalwin);
	write("����Ϸ������"+totalplay+"  �����룺"+totalbet+" �ܽ���"+totalwin+" ����"+temp+" �� ���ϵ�λ��Ϊ������\n");
	return 1;
}

int do_food()
{
	tell_object(this_player(), "�Ժ��뵽��¥������\n");
	return 1;
}

int do_skills(string arg)
{
	tell_object(this_player(), "��ô��������ʲô������һ����˵�ɡ�\n");
	return 1;
}

int do_study(string arg)
{
	tell_object(this_player(), "���鿼״Ԫ�������Ǯ׬��Բ��\n");
	return 1;
}


int do_outhere()
{
	object me,jjj;
	int mpjj,mejl;
	me = this_player();
	jjj = new ("/clone/money/gold");
	mejl = me->query("max_jingli");

	if((int)me->query("jingli") < (mejl/10))
	{
		write("Ъ�������������߰ɣ�\n");
		return 1;
	}

// �����д󽱡���
	me->add("jingli", -(mejl/15));
	mpjj = (random(200));

	if(mpjj == 88)
	{
		jjj->set_amount(50);
		jjj->move(me);
		tell_room(environment(me),(string)me->query("name")+"������Ʊ�Խ�һ����������ϲ�����������˳�ȥ��\n",me);
		me->move(__DIR__"dc_door");
		tell_object(me,""HIM"��������Ʊ�󽱣���������Ϊ50���ƽ�"NOR"\n");
		tell_room(environment(me),(string)me->query("name")+"��ϲ����شӶĳ�����˳������㼸����ײ���ڵء�\n",me);
		tell_object(me,"�����˳�����\n");
		CHANNEL_D->do_channel(me, "rumor", sprintf(HIY"%s����50���ƽ����Ʊ�󽱣�"NOR, me->query("name")));
		CHANNEL_D->do_channel(me, "rumor*", "yeah");
		return 1;
	}

	if(mpjj > 180)
	{
		jjj->set_amount(3);
		jjj->move(me);
		tell_room(environment(me),(string)me->query("name")+"������Ʊ���˶Խ���Ȼ�����������������˳�ȥ��\n",me);
		me->move(__DIR__"dc_door");
		tell_object(me,""HIM"��������Ʊ���˽�������Ϊ3���ƽ�"NOR"\n");
		tell_room(environment(me),(string)me->query("name")+"�Ӷĳ������˳�����������ͦ���ĵġ�\n",me);
		tell_object(me,"�����˳�����\n");
		return 1;
	}

	if(mpjj <80)
	{
		jjj->set_amount(1);
		jjj->move(me);
		tell_room(environment(me),(string)me->query("name")+"������Ʊ���˶Խ���Ȼ����˵��������˳�ȥ��\n",me);
		me->move(__DIR__"dc_door");
		tell_object(me,""HIM"��������Ʊ��ο��������Ϊ1���ƽ�"NOR"\n");
		tell_room(environment(me),(string)me->query("name")+"�Ӷĳ������˳�����������ͦ���ĵġ�\n",me);
		tell_object(me,"�����˳�����\n");
		return 1;
	}

// û�н�������
	tell_room(environment(me),(string)me->query("name")+"�������ذ���Ʊ˺��һ�ӣ��������˳�ȥ��\n",me);
	me->move(__DIR__"dc_door");
	tell_object(me,""HIM"����˶Խ�ȥʱ�����Ʊ��û���н�����"NOR"\n");
	tell_object(me,"�����˳�����\n");
	tell_room(environment(me),(string)me->query("name")+"�Ӷĳ������˳������ƺ���ɫ��̫�á�\n",me);
	return 1;
}


int do_bet(string arg)
{
	object qian,g_qian,jj,g_jj,me;
	int gamea,gameb,gamec,gameall,betmoney;
	string betname,gamename;

	me = this_player();
	qian = present("silver_money", me);
	g_qian=present("gold_money",me);
	g_jj=new("/clone/money/gold");
	jj = new("/clone/money/silver");

	if (time()-query_temp("playtime")<2)
	return notify_fail("�Ǳ�Χ�����ˣ����ǵȻ���ٹ�ȥ��ɡ�\n");

	if (!arg || sscanf(arg, "%s %d", betname, betmoney) !=2)
	return notify_fail("��ҪѺʲô�� ��bet <��/С> <����>��\n");

	if(betmoney<1)
	return notify_fail("�����˼����Ҫ׼����Ǯ��\n");

	if(betmoney>50)
	return notify_fail("����ֻ����1-50�����ӵ�Ѻע��\n");

	if(!qian || (int)qian->query_amount() < betmoney)
	{
		if(!g_qian)
		{
			message_vision("$N����ض��Ż���˵������Ǯ������Ѻ��ע���𣿡���������û���κη�Ӧ��\n",me);
			return 1;
		}
	}

	if(betname == "��" || betname == "С")
	{
		totalplay++;
		totalbet+=betmoney;
		jj->set_amount(betmoney);

		gamea = (1+random(6));
		gameb = (1+random(6));
		gamec = (1+random(6));

		tell_object(me,"�����������������һ��ҡ�ˣ������ˣ�" + gamea + "��" + gameb + "��" + gamec +  "��\n");
		tell_room(environment(me),(string)me->query("name")+"��������������һ����һ�߽е�����"+betname+"��"+betname+"��"+betname+"��������\n",me);

		if(gamea == gameb && gamea == gamec)
		{
			tell_object(me,"����һ����������Ѻ���Ǵ���С�����н���\n");
			message_vision("$N���˽���Ц����ذѽ�������������\n",me);
			jj->move(me);
			totalwin+=(betmoney*2);
			set_temp("playtime",time());
			return 1;
		}

		gameall =(gamea+gameb+gamec);
		if(gameall > 10)
			gamename = "��";
		if(gameall < 11)
			gamename = "С";

		tell_object(me,"������" + gameall + "�㣬" + gamename + "��\n");

		if(betname == gamename)
		{
			tell_object(me,"��Ѻ����" + betname + "���н��ˣ�����\n");
			message_vision("$N���˽���Ц����ذѽ�������������\n",me);
			jj->move(me);
			totalwin+=(betmoney*2);
			set_temp("playtime",time());
			return 1;
		}

		message_vision("û���н���$Nĥ��ĥ����\n",me);
		if(!qian || (int)qian->query_amount() < betmoney)
		{
			g_qian->add_amount(-1);
			jj->set_amount(100-betmoney);
			if(!qian) jj->move(me);
			else qian->add_amount(100-betmoney);

		totalwin+=(betmoney*2);
		set_temp("playtime",time());
		return 1;
		}

		qian->add_amount(-betmoney);
		return 1;
	}

	write("��ҪѺʲô�� ��bet <��/С> <����>��\n");
	return 1;
}

