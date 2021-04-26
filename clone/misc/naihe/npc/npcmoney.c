// NPC���ϻ���������  ��/npc/npcmoney.c
// by naihe  2002-04-09
// ������ı��ļ�Դ�룬лл��
// 4-26 �����Ϸ"kick". 4-27 �����Ϸ"yazhu".
// 4-29 �������Ϸ��������һ����֪���������NPC������

#include <ansi.h>
inherit NPC;

int t_bet,t_play,t_win;

void create()
{
	set_name(HIG"�ϻ���"NOR,({"npc money","money"}));
	set("long","\n����һ̨���εĻ���������Q��״��С�ϻ�ģ�����ǳ��ɰ������Ų�������
��������ǻλ�����кö��"HIW"����"NOR"(silvers)��ֻҪ����"HIR"��"NOR""HIW"��kick money��"NOR"����
����������Ϸ��ÿ���Զ���ȡ���һ��������\n\n");
	set("nickname",HIR"ҡ��ʽ"NOR);
	set("title",HIC"�����˹���������Ʒ"NOR);
	set("gender","����");
	set("age",19);
	set("attitude","friendly");
	set("str",60);
	set("int",30);
	set("con",60);
	set("dex",30);
	set("qi",100000);
	set("max_qi",100000);
	set("max_jing",100000);
	set("jing",100000);
	set("jingli",100000);
	set("max_jingli",100000);
	set("neili",100000);
	set("max_neili",100000);
	set("jiali",1);
	set("combat_exp",52013140);
	set_skill("force",401);
	set_skill("dodge",401);
	set_skill("parry",401);
	set_skill("literate",401);
	set_skill("music",401);
        set("no_refresh",1);
	set("inquiry",([
	    "����":"�ϻ����ɻ�ɽ���κ�������\n�ϻ�������Զ������գ������س���",
	    "ҡ��ʽ":"
Ϊʲô������ôҡ��\n��Ϊ������Ա߽У�\nΪʲô�����Ա߽У�\n��Ϊ����Ǯ������Ц��\nҡ��ʽ����ҡ�����  ����",
	    "play":"������kick �� yazhu ������Ϸ�������ѯ�� <����>�õ���ϸ���ܣ�",
	    "����":"kick ��Ϸ��ֻҪ�����ߣ�"HIW"kick money"NOR"�������ذ��»س��������㽫���н���\n yazhu��Ϸ������ "HIW"yazhu <ɵ��> <����>"NOR"�������ɵ�ϣ��㽫���н���",
	    ]));
	set("chat_chance",1);
	set("chat_msg",({
	    "�ϻ����������ţ�����ƭǮ������Ǯ������һ������Ǯ����������ϻ���ѽ����\n",
	    "�ϻ����������ţ���ֻҪ��һ�ţ�"HIW"kick money"NOR"�����л����ô������������ѽ����\n",
	    "�ϻ����������ţ�����Ѻע��"HIW"yazhu <ɵ��> <����>"NOR"�������л����������������ѽ����\n",
	}));
	setup();
	add_money("coin",1);
}

void init()
{
        ::init();  // ��ʵ�ڲ����������ʲô�ð�
	if (wizardp(this_player()))  add_action("do_xxxxx", "xxxxx"); // wiz ���Բ�ѯ��ֵ��
        add_action("do_kick", "kick");
	add_action("do_killme", "kill");
	add_action("do_yazhu", "yazhu");
	add_action("do_throw", "throw");

}


int do_xxxxx()
{
	int temps;
	temps = (t_bet-t_win);
     	write("��Ϸ������"+t_play+ "��  ���룺"+temps+" �� ��\n��Ѻע��"+t_bet+" ��  �ܽ���"+t_win+" ����\n");
	return 1;
}

int do_throw(string arg)
{
	tell_object(this_player(),"��Ҫ���Ӷ�����һ��С���ҵ��ϻ����ɲ��á���\n");
	return 1;
}

int do_killme(string arg)
{
	object me;
	me = this_player();
	if(arg == "money" || arg == "npc money")
	{
	tell_object(me,"��ͻȻ�����ϻ���̫�ɰ��ˣ����ɵ�������������\n");
	return 1;
	}

	return 0;
}

int do_kick(string arg)
{
	object me,qian,jjout,lkout;
	int gamea,gameb,gamec,lucka,luckb,luckc,jj;
	me = this_player();
	qian = present("silver_money", me);
	jjout = new("/clone/money/silver");
	lkout = new("/clone/money/silver");

	if (time()-query_temp("playtime")<2)
	{
	tell_object(me,"��һ����Ϸ��û���أ��ȵȰɡ�\n");
	return 1;
	}

	if(!arg || arg !="money")
	return 0;

	if(!qian)
	{
	tell_object(me,"���ߣ��߻��˿�ûǮ�⡣\n");
	return 1;
	}

	tell_object(me,"������ϻ���һ�����˹�ȥ��������������Ϸ�����ˡ���\n");
	tell_room(environment(me),(string)me->query("name")+"����һ�ţ����������ϻ�����ƨ�ɣ�\n",me);


// ��������Ϸ��ʼ�Ĳ��֡� ��100�С�
	qian->add_amount(-1);
	t_play++;
	t_bet++;

// ȡ��һ����ֵ��
	switch(random(3))
	{
		case 0 :
	tell_object(me,"1--"HIG"��"NOR"\n");
	gamea = 1;
		break;

		case 1:
	tell_object(me,"1--"HIY"��"NOR"\n");
	gamea = 2;
		break;

		case 2:
	tell_object(me,"1--"HIM"��"NOR"\n");
	gamea = 3;
		break;

/*		case 3:
	tell_object(me,"1--"HIW"��"NOR"\n");
	gamea = 4;
		break; */
	}

// ȡ�ڶ�����ֵ��
	switch(random(3))
	{
		case 0 :
	tell_object(me,"2--"HIG"��"NOR"\n");
	gameb = 1;
		break;

		case 1:
	tell_object(me,"2--"HIY"��"NOR"\n");
	gameb = 2;
		break;

		case 2:
	tell_object(me,"2--"HIM"��"NOR"\n");
	gameb = 3;
		break;

/*		case 3:
	tell_object(me,"2--"HIW"��"NOR"\n");
	gameb = 4;
		break; */
	}
	
// ȡ��������ֵ��
	switch(random(3))
	{
		case 0 :
	tell_object(me,"3--"HIG"��"NOR"\n");
	gamec = 1;
		break;

		case 1:
	tell_object(me,"3--"HIY"��"NOR"\n");
	gamec = 2;
		break;

		case 2:
	tell_object(me,"3--"HIM"��"NOR"\n");
	gamec = 3;
		break;

/*		case 3:
	tell_object(me,"3--"HIW"��"NOR"\n");
	gamec = 4;
		break; */
	}

	if(gamea == gameb && gamea == gamec)
	{
	jj = 5 + (random(6));
	jjout->set_amount(jj);
	tell_object(me,"�н��ˣ���������Ϊ" + jj + "�����ң�����\n");
	tell_object(me,"�ϻ�����ϡ�����������³�һ��"HIW"����"NOR"���������̵�����������\n");
	tell_room(environment(me),"�ϻ�����ϡ�����������³�һ��"HIW"����"NOR"��" + (string)me->query("name") + "�����̵�����������\n",me);
	jjout->move(me);
	t_win+=jj;

		if(jj > 7)
		{
		tell_object(me,""HIY"�㽫�л����е����˽�����"NOR"\n");
		lucka = (random(5));
		luckb = (random(5));
			if (lucka == luckb)
			{
			luckc = (lucka*2 + 5);
			lkout->set_amount(luckc);
			t_win+=luckc;
			lkout->move(me);
			tell_object(me,"���������˽���\n");
			tell_object(me,"�ϻ�����ϡ�������������³�" + luckc + "��"HIW"����"NOR"������˵ó��������\n");
			tell_room(environment(me),"�ϻ�����ϡ�������������³�һ��"HIW"����"NOR"��ԭ��" + (string)me->query("name") + "˳���������˽���\n",me);
			}

			else
			tell_object(me,"û���е����˽���\n");  //��200�С�
		}

	set_temp("playtime",time());
	return 1;
	}

	tell_object(me,"û���н��� :P\n");
	set_temp("playtime",time());
	return 1;
}


int do_yazhu(string arg)
{
	object me,qian,jj;
	string game,betname;
	int jjout,betmoney;
	me = this_player();
	qian = present("silver_money", me);
	jj = new("/clone/money/silver");

	if (time()-query_temp("playtime")<2)
	{
	tell_object(me,"��һ����Ϸ��û���أ��ȵȰɡ�\n");
	return 1;
	}

	if(!qian)
	return notify_fail("�㶼û����Ѻʲôע����������ѽ������\n");

	if (!arg || sscanf(arg, "%s %d", betname, betmoney) !=2) 
	return notify_fail("��ҪѺʲô����ɵ�� ľ�� ����ɵ�� ���� ���� ����������\n��ʽ��yazhu <����> <����>\n");

	if(betmoney<1 || betmoney>20)
	return notify_fail("����ֻ����1�����ϡ�20�����µ�����Ѻע��\n");

	if((int)qian->query_amount() < betmoney)
	return notify_fail("���Ǯ������Ѻʲôע�������ǲ���׼����Ǯ������\n");

	if(betname == "ɵ��" || betname == "ľ��" || betname == "����ɵ��" || betname == "����" || betname == "����" || betname == "��������")
	{
	qian->add_amount(-betmoney);
	tell_room(environment(me),"ֻ��" + (string)me->query("name") + "�ó�һЩ���ӣ�ҧ���гݵ�Ѻ�˸�ʲô��\n",me);	
	tell_object(me,"��Ѻ���ǣ�" + betname + "��\n");
	}

	else
	return notify_fail("��ҪѺʲô����ɵ�� ľ�� ����ɵ�� ���� ���� ����������\n��ʽ��yazhu <����> <����>\n");

// ���濪ʼ��Ϸ����������289--271�����ҡ�
	t_play++;
	t_bet+=betmoney;

	switch(random(6))
	{
		case 0 :
	game = "ɵ��";
		break;

		case 1 :
	game = "ľ��";
		break;

		case 2 :
	game = "����ɵ��";
		break;
		
		case 3 :
	game = "����";
		break;

		case 4 :
	game = "����";
		break;

		case 5 :
	game = "��������";
		break;
	}

	tell_object(me,"�ϻ����Ǹ�" + game + "��\n");
	if(game == betname)
	{
	tell_object(me,"��Ѻ��" + betname + "�н��ˣ�\n");
		if(game == "����ɵ��" || game == "��������")
		{
		jjout = ((1+random(9))*betmoney);
		jj->set_amount(jjout);
		t_win+=jjout;
		jj->move(me);
		}

		else
		{
		jjout = (5*betmoney);
		jj->set_amount(jjout);
		t_win+=jjout;
		jj->move(me);
		}

		tell_object(me,"����Ϊ" + jjout + "������ӭ�´�����ѽ  ����\n");
		tell_room(environment(me),(string)me->query("name") + "Ѻ��" + betname + "�н��ˣ�\n",me);
		set_temp("playtime",time());
		return 1;
	}

	tell_object(me,"��Ѻ����" + betname + "��������" + game + "��û���н�����ӭ�´�����ѽ ����\n");
	command("kiss");
	set_temp("playtime",time());
	return 1;
}
