//                ��׼��������ʾ��                                   |
// �κεĶĳ�����  ��dc_dating.c
// by naihe  2002-04-23  ��ï��
// naihe ��2002-05-17�����޸����Ʊ��ļ�
// �ĳ�����Ϸ���ʾ������ϸ���ԣ��޸ı��ļ����ʵȴ��������أ�

#include <ansi.h>
#include <room.h>
inherit ROOM;

int totalplay,totalbet,totalwin,t_betgold,t_wingold,topjj,toptopjj;

void create()
{
	set("short", HIY"�ĳ�����"NOR);
	set("long", "�����Ƕĳ��Ĵ������ſ���һ���ɰ���С�������ڲ��ϵغͽ����Ŀ��˴���
������������ڷ����ų�һȦ����ಿ����Ļ�����jiqi����ֻ�������ǡ��ס���
�������ز��Ϸ���������������������Ŀմ���һ�� ATM��Ա������˵������
�Ļ�����ʹ����ʱ������Ǯׯ��һ�����㡣���������м���Сͨ�������ߵ�ͨ��
�����������ǻ�������ʾ������������С�������ǹ����������λ�õ���ƫ
���������ϱ�����ϴ�ּ䡣¥����һ��������Ĳ����������������˶�����ȥ
�Ե㶫������Ϣһ�ᡣֻ�����������ŵ�ǽ������Ŀ�Ĺ���һ��С���ӣ�paizi����\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up","1");
	set("invalid_startroom",1);

	set("item_desc",([
	    "paizi":"���������֣���Ӯ������\n",
	    "jiqi":"������д������˵����Ĭ��ÿ��5������������(games)������Ϸ����Ҫ��ע������:
games a--10��������games b--20������,games c--30��������games yeah--50��������
���룺cktop �����Բ�ѯ���ڵ��ۻ��󽱽�\n",
	]));

	set("objects", ([
	    __DIR__"npc/atm" : 1,
	    __DIR__"obj/yizi" : 1,
	    ]));

	set("exits", ([
	    "east": __DIR__"dc_horse",
	    "west":__DIR__"dc_robot",
	    "southeast":__DIR__"dc_bigsm",
	    "southwest":__DIR__"dc_lav",
	    "vip":__DIR__"dc_vip",
	    "up":__DIR__"dc_chazuo",
//	    "out":__DIR__"dc_door",
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
	add_action("do_games", "games");
	add_action("do_out", "out");
	add_action("do_note", "note");
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_food", "drink");
	add_action("do_cktop","cktop");
}

int do_cktop(object me)
{
	write("���ڵ��ۻ��󽱽��Ϊ�� "+topjj+" ��������\n");
	write("���Ѻע��������ܹ��õ����ٷݶ���ۻ�����
<games> 10% ��<games a> 20% ��<games b> 40% ��<games c> 60% ��<games yeah> 100%.\n");
	return 1;
}

int do_xxx()
{
	int temps,tempg;
	temps = (totalbet-totalwin);
	tempg = (t_betgold-t_wingold);
     	write(""HIY"��Ϸ������"+totalplay+ "��  ���룺"+tempg+" �� "+temps+" �� ��\n��Ѻע��"+t_betgold+" �� "+totalbet+" ��  �ܽ���"+t_wingold+" �� "+totalwin+" ����\n��ʷ�ۻ����ܶ�Ϊ�� "+toptopjj+" ��  ��ǰ�ۻ��󽱣� "+topjj+ " ����"NOR"\n");
	return 1;
}

int do_note(string arg)
{
	if(!arg)
	{
		if(wizardp(this_player()) || this_player()->query("id") == "naihe")
		{
		new(__DIR__"npc/obj/note_naihe")->move(this_player());
		write("note ok.\n");
		return 1;
		}
	}
	return 0;
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

int do_games(string arg)
{
	object qian,g_qian,jj,jjg,me;
	int games,plerbet,jjout,topjjout,tempa,tempb;
	string betname,bettest,winner;

	me = this_player();
	qian = present("silver_money", me);
	g_qian=present("gold_money",me);

	jj = new("/clone/money/silver");
	jjg= new("/clone/money/gold");

	if (time()-query_temp("playtime")<2)
	return notify_fail("�Ǳ�Χ�����ˣ����ǵȻ���ٹ�ȥ��ɡ�\n");

// ���û����Ҳû�ƽ𣬲�����Ϸ��
	if(!qian && !g_qian)
	return notify_fail("��ҡ����1000���Ĵ󽱣�������ϧ��ûǮѺ��\n");

// ���漴����ʼ��Ϸ��

// �����ֱ�����롰games����������������жϡ�
	if(!arg)
	{
		plerbet=5;

// ����������û�����ӣ�һ��Ҫ����䣬��Ȼ���д��󣩻������ٹ�Ѻע�����лƽ��жϣ�
// ���Ҳû�лƽ𣬲�����Ϸ������У�ֱ�ӿ۳��ƽ𲢸�����Ӧ���ӡ�
		if(!qian || (int)qian->query_amount() < plerbet)
		{
			if(!g_qian) return notify_fail("��ҡ����1000���Ĵ󽱣�������ϧ�㲻��Ǯ��ûѺ�ϡ�\n");
			g_qian->add_amount(-1);
			jj->set_amount((100-plerbet));
			jj->move(me);
		}

		else qian->add_amount(-5);

// �ۻ����ۼӣ���Ѻע��ͳ�ƣ���ʷ�ۻ���ͳ�ơ�
		totalbet+=5;
		topjj+=(plerbet/5);
		toptopjj+=(plerbet/5);
	}

// �������ֱ�����롰games�������ǻ���������Ϣ�Ļ���������������жϡ�
	else
	{

// ���������Ԥ��ļ�����Ϣ֮һ�������ʾ�䣬��������Ϸ��
		if(arg!="a" && arg!="b" && arg!="c" && arg!="yeah")
			return notify_fail("��ʽ��games <����>\n");
		if(arg == "a") plerbet=10;
		if(arg == "b") plerbet=20;
		if(arg == "c") plerbet=30;
		if(arg == "yeah") plerbet=50;

// ͬ������жϳ���������������ٹ�Ѻע�Ľ����лƽ��жϡ�
		if(!qian || (int)qian->query_amount() < plerbet)
		{
			if(!g_qian) return notify_fail("��ҡ����1000���Ĵ󽱣�������ϧ�㲻��Ǯ��ûѺ�ϡ�\n");
			g_qian->add_amount(-1);
			jj->set_amount(100-plerbet);
			jj->move(me);
		}

		else qian->add_amount(-plerbet);

// ����ͳ�����ݡ�
		totalbet+=plerbet;
		topjj+=(plerbet/5);
		toptopjj+=(plerbet/5);
	}

// ����Ϸ�����ۼ�һ�Ρ�
	totalplay++;

// ����һЩ����ۿ���Ϸ��Ѻע����������ļ��㣬����������ɻƽ����
	if(totalbet>499)
	{
	totalbet-=500;
	t_betgold+=5;
	}

	if(totalwin>499)
	{
	totalwin-=500;
	t_wingold+=5;
	}

// ��������Ļƽ����Ѻע�Ļƽ��30-60���Ļ�������Ӵ��Ѷȡ�

	if((t_wingold-t_betgold) > (30+random(30)))
	{
		games = (random(300+plerbet*2));
		if(wizardp(me)) write("�Ӵ��Ѷ��ˡ�\n");
	}

// �����û�����ô�࣬���������ʣ���˼���ǻ�Ҫ����㣬�Ż�Ӵ��Ѷȡ������������䣬
// ��ĳ��ϰ�ɲ��õ�ѽ����
	else
	{
		games = (random(200));
		if(wizardp(me)) write("�������ʡ�\n");
	}

// ����ҡ���жϡ����ڵ��жϱȽ����У��ĳ�������̫�࣬���Ҳ�л���Ӯ�󽱣�
	if(games > 100 && games < 121)
	{
		tell_object(me,"��ҡ���ˣ�"HIM"�I"NOR"\n"),
		jjout = (plerbet*3);
		winner="yes";
		tell_object(me,"�н��ˣ�����3����" + jjout + "����\n"),
		tell_room(environment(me),(string)me->query("name") + "���˸���С�Ľ���\n",me);
	}

	if(games < 10)
	{
		tell_object(me,"��ҡ���ˣ�"HIM"��"NOR"\n"),
		jjout = (plerbet*5);
		winner="yes";
		tell_object(me,"�н��ˣ�����5����" + jjout + "����\n"),
		tell_room(environment(me),(string)me->query("name") + "���˸��ڶ�С�Ľ���\n",me);
	}

	if(games == 16 || games == 17 || games == 18 || games == 19)
	{
		tell_object(me,"��ҡ���ˣ�"HIM"��"NOR"\n"),
		jjout = (plerbet*10);
		winner="yes";
		tell_object(me,"�н��ˣ�����10����" + jjout + "����\n"),
		tell_room(environment(me),(string)me->query("name") + "���˸����Ƚ���\n",me);	
	}

	if(games == 21 || games == 22 || games == 23)
	{
		tell_object(me,"��ҡ���ˣ�"HIM"��"NOR"\n"),
		jjout = (plerbet*20);
		winner="yes";
		tell_object(me,"�н��ˣ�����20����" + jjout + "����\n"),
		tell_room(environment(me),(string)me->query("name") + "���˴󽱣�����\n",me);	
	}

	if(winner !="yes" && random(500) == 24)
	{
		tell_object(me,"��ҡ���ˣ�"HIR"��"NOR"\n"),
		jjout = (plerbet*100);
		winner="yes";
		tell_object(me,"���˴󽱣�����������100����" + jjout + "������̫�����ˣ�\n"),
		tell_room(environment(me),"�ۣ�����" + (string)me->query("name") + "������ߵĽ������\n",me);
		CHANNEL_D->do_channel(me, "rumor", sprintf(""HIY"%s����100������Ϸ�󽱣�"NOR"", me->query("name")));
		CHANNEL_D->do_channel(me, "rumor*", "yeah");
	}

// �������н��ˣ����̸�����������99�����ӣ���֧����Ӧ�����Ļƽ�
// Ϊ�˱���ϵͳ������ǡ������������������ʱ��֧����Ӧ�Ļƽ�֮�⣬����
// ����һ�����ӡ�
	if(winner=="yes")
	{
		if(jjout>99)
		{
			tempa=(jjout/100);
			tempb=(jjout-tempa*100);
			jjg->set_amount(tempa);
			jjg->move(me);
			if(tempb==0) jj->set_amount(1);
			else jj->set_amount(tempb);
		}

		else jj->set_amount(jjout);

// ��������ͳ�ơ�
		totalwin+=jjout;

		jj->move(me);
		tell_object(me,"���ڵ��ۻ���Ϊ�� "+topjj+" ��������\n");

// ��ʱ������л����е��ۻ��󽱣��ۻ��󽱵��Ѷ���Ѻע���е���ϵ��������������˵��
// Ѻע��Խ���н�����ԽС�㡣
		if(random(100+plerbet) == 88)
		{
			if(plerbet==5) topjjout=(topjj/10);
			if(plerbet==10) topjjout=(topjj/5);
			if(plerbet==20) topjjout=(topjj*2/5);
			if(plerbet==30) topjjout=(topjj*3/5);
			if(plerbet==50) topjjout=(topjj);

			tell_object(me,"�������ۻ��󽱣���������Ϊ "+topjjout+" ������������\n");

// �����ۻ���ʱ��ҥ��Ƶ���ᱨ��������ɫ��Ϊ��ȷ����ϵͳ��˵���Ӷ�һ�䡰yeah������
// Ϊ�˷�ֹ���������λᱻϵͳ�ԡ���ͬ�Ļ���Ҫ˵�������˵��������

			CHANNEL_D->do_channel(me, "rumor", sprintf(HIG"%s����"+topjj+"�����ӵ��ۻ���Ϸ����"NOR, me->query("name")));
			CHANNEL_D->do_channel(me, "rumor*", "yeah");

// ���������Ҳ�ͳ�ơ�
			if(topjjout>99)
			{
				tempa=(topjjout/100);
				tempb=(topjjout-tempa*100);
				jjg->set_amount(tempa);
				jjg->move(me);
				if(tempb==0) jj->set_amount(1);
				else jj->set_amount(tempb);
			}

			else jj->set_amount(topjjout);

			totalwin+=topjjout;
			topjj-=topjjout;
			jj->move(me);

		}
		set_temp("playtime",time());
		return 1;
	}

// �����н��жϽ���������������Ĳ��н���������

	switch(random(15))
	{
		case 0 :
	tell_object(me,"��ҡ���ˣ�"HIG"��"NOR"\n");
		break;

		case 1 :
	tell_object(me,"��ҡ���ˣ�"HIG"��"NOR"\n");
		break;

		case 2 :
	tell_object(me,"��ҡ���ˣ�"HIG"��"NOR"\n");
		break;

		case 3 :
	tell_object(me,"��ҡ���ˣ�"HIG"��"NOR"\n");
		break;

		case 4 :
	tell_object(me,"��ҡ���ˣ�"HIG"��"NOR"\n");
		break;

		case 5 :
	tell_object(me,"��ҡ���ˣ�"HIG"��"NOR"\n");
		break;

		case 6 :
	tell_object(me,"��ҡ���ˣ�"HIG"��"NOR"\n");
		break;

		case 7 :
	tell_object(me,"��ҡ���ˣ�"HIG"��"NOR"\n");
		break;

		case 8 :
	tell_object(me,"��ҡ���ˣ�"HIG"��"NOR"\n");
		break;

		case 9 :
	tell_object(me,"��ҡ���ˣ�"HIG"��"NOR"\n");
		break;

		case 10 :
	tell_object(me,"��ҡ���ˣ�"HIG"��"NOR"\n");
		break;

		case 11 :
	tell_object(me,"��ҡ���ˣ�"HIG"��"NOR"\n");
		break;

		case 12 :
	tell_object(me,"��ҡ���ˣ�"HIG"��"NOR"\n");
		break;

		case 13 :
	tell_object(me,"��ҡ���ˣ�"HIG"��"NOR"\n");
		break;

		case 14 :
	tell_object(me,"��ҡ���ˣ�"HIG"��"NOR"\n");
		break;
	}

	tell_object(me,"û���н���\n");
	tell_object(me,"���ڵ��ۻ���Ϊ�� "+topjj+" ��������\n");
	set_temp("playtime",time());
	return 1;
}

int do_out(string arg)
{
	object me,jjj;
	int mpjj,mejl;
	me = this_player();
	jjj = new ("/clone/money/gold");
	mejl = me->query("max_jingli");

	if((int)me->query("jingli") < (mejl/10))
	return notify_fail("Ъ�������������߰ɣ�\n");

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