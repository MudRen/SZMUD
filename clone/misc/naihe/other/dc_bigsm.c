//                ��׼��������ʾ��                                   |
// �Ĵ�С�ķ��䣬ƫ��������  ��dc_bigsm.c
// by naihe  2002-04-28  ��ï��
// �������Ը��ı��ļ�Դ�룬лл��

#include <ansi.h>
#include <room.h>
inherit ROOM;

int totalplay,totalbet,totalwin;

void create()
{
	set("short", YEL"�ĳ�ƫ��"NOR);
	set("long", "�����Ƕĳ���ƫ��������һ�������һ�㣬�������λ��Χ��һȦ��������
��Ļ����������桰��С����Ϸ�ģ���Ҫ�ȴ�������Щ����������Ȼ�ǳ������ҡ�
�������涼����Ϸ��˵����shuoming����\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);

	set("item_desc",([
    "shuoming":"ÿ��1-50������������(bet <��/С> <����>)������Ϸ��4-10ΪС��11-17Ϊ��\n",
    "shuoming":"ÿ��1-50������������(bet <��/С> <����>)������Ϸ��4-10ΪС��11-17Ϊ��\n",
	]));

	set("objects", ([
	    __DIR__"obj/yizi" : 1,
	    ]));

	set("exits", ([
	    "northwest":__DIR__"dc_dating",
	    ]));

	setup();
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
	add_action("do_bet", "bet");
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_food", "drink");
        add_action("do_food", "he");
}

  void reset() 
  { 
                ::reset(); 
                set("no_clean_up", 1); 
  } 

int do_xxx()
{
	int temp =(totalbet-totalwin);
	write("����Ϸ������"+totalplay+"  �����룺"+totalbet+" �ܽ���"+totalwin+" ����"+temp+" ��\n");
	return 1;
}

int do_food(string arg)
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

int do_bet(string arg)
{
	object qian,jj,me;
	int gamea,gameb,gamec,gameall,betmoney;
	string betname,gamename;

	me = this_player();
	qian = present("silver_money", me);
	jj = new("/clone/money/silver");

	if (time()-query_temp("playtime")<1)
	return notify_fail("�Ǳ�Χ�����ˣ����ǵȻ���ٹ�ȥ��ɡ�\n");

	if(!qian)
	return notify_fail("������ض��Ż���˵������û���ӣ�Ѻ��ע���𣿡���������û���κη�Ӧ��\n");

	if (!arg || sscanf(arg, "%s %d", betname, betmoney) !=2)
	return notify_fail("��ҪѺʲô�� ��bet <��/С> <����>��\n");
//��100�С�
	if((int)qian->query_amount() < betmoney)
	return notify_fail("������ض��Ż���˵���������Ӳ�����Ѻ��ע���𣿡���������û���κη�Ӧ��\n");

	if(betmoney<1)
	return notify_fail("�����˼����Ҫ׼����Ǯ��\n");

        if(betmoney>50)
        return notify_fail("����ֻ����1-50�����ӵ�Ѻע��\n");

	if(betname == "��" || betname == "С")
	{
		totalplay++;
		totalbet+=betmoney;
		qian->add_amount(-betmoney);
		jj->set_amount(betmoney*2);

		gamea = (1+random(6));
		gameb = (1+random(6));
		gamec = (1+random(6));

		tell_object(me,"�����������������һ��ҡ�ˣ������ˣ�" + gamea + "��" + gameb + "��" + gamec +  "��\n");
		tell_room(environment(me),(string)me->query("name")+"��������������һ��������ϣ����������ҡ�ˡ�\n",me);

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
		set_temp("playtime",time());
		return 1;
	}
	else tell_object(me,"��ҪѺʲô�� ��bet <��/С> <����>��\n");
	return 1;
}
