//                ��׼��������ʾ��                                   |
// ���䣬�������ĳ��ľ�����Ϸ��  ��adj.c
// by naihe  2002-04-23  ��ï��
// naihe ��2002-05-17�����޸����Ʊ��ļ�
// 02-05-18�����޸ģ���ֱ����Ѫ������ �汾3.0~~
// 02-05-20 �Ӹ����ϸ��������ʷ�ʽ�����ڲ�����Ǯ��Ҳ����Ӯ��ҵ�Ǯ����
// �ĳ�����Ϸ���ʾ������ϸ���ԣ��޸ı��ļ����ʵȴ��������أ�
// ���ļ���ԭdc_dating.c �ı������

#include <ansi.h>
inherit ROOM;

int t_playtimes,t_bets,t_betg,t_wins,t_wing,leiji,t_leiji,level,
level=1;
// ���ϱ����ֱ��ǣ�
// ����Ϸ�������ܰ���Ѻע��ܻƽ�Ѻע��ܰ����н������ܻƽ��н�����
// ��ǰ�ۻ�������ʷ�ۻ����𣬵�ǰ��Ϸ�Ѷȡ�

void create()
{
        set("short", HIG"һ��С����"NOR);
	set("long", "����һ��С���䣬�����м���������������ʹ��������˿����������ͦ
�ľ��ģ������������������Ϸ�ˡ�����ֻ����һ��������jiqi�������������
������ͬ���������ص���ǿ����ۻ������㲻��ԾԾ���ԡ�\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up","1");
	set("invalid_startroom",1);

	set("item_desc",([
	    "jiqi":"������д������˵����Ĭ��ÿ��5������������(games)������Ϸ����Ҫ��ע������:
games a--10��������games b--20������,games c--30��������games yeah--50��������
���룺cktop �����Բ�ѯ���ڵ��ۻ��󽱽�\n",
	]));

	set("exits", ([
	    "out":__DIR__"dc_dating",
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
	add_action("do_games", "games");
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_food", "drink");
	add_action("do_food", "he");
	add_action("do_cktop","cktop");
}

  void reset() 
  { 
                ::reset(); 
                set("no_clean_up", 1); 
  } 

int do_cktop(object me)
{
	write("���ڵ��ۻ��󽱽��Ϊ�� "+leiji+" ��������\n");
	write("���Ѻע��������ܹ��õ����ٷݶ���ۻ�����
<games> 10% ��<games a> 20% ��<games b> 40% ��<games c> 60% ��<games yeah> 100%.\n");
	return 1;
}

int do_xxx(string arg)
{
	if(!arg)
	{
		int temps,tempg;
		temps = (t_bets-t_wins);
		tempg = (t_betg-t_wing);
     		write(""HIY"��Ϸ������"+t_playtimes+ "��  ���룺"+tempg+" �� "+temps+" �� �����ڵ��Ѷ�Ϊ "+level+".\n��Ѻע��"+t_betg+" �� "+t_bets+" ��  �ܽ���"+t_wing+" �� "+t_wins+" ����\n��ʷ�ۻ����ܶ�Ϊ�� "+t_leiji+" ��  ��ǰ�ۻ��󽱣� "+leiji+ " ����"NOR"\n");
	}

	if(arg=="easy") level=1;
	if(arg=="hard") level=21;
	if(arg=="pro") level=51;

	if(arg && arg!="easy" && arg!="hard" && arg!="pro") write("ָ���ʽ��<xxx easy/hard/pro>\n");

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

//$$$$$$$$$$$$$$$$$$$$$$$$$$  ��ʼ��Ϸ��  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

int do_games(string arg)
{
	object s_qian,g_qian,s_jj,g_jj,me;
// ���ϱ���Ϊ��������ϵİ�����������ϵĻƽ�ϵͳ���õİ�����ϵͳ���õĻƽ��Լ�me.

	int games,plerbet,jjout,leiji_jjout,peilv,tempa,tempb,win_lose,nowrandom,tempp,tempq;
// ���ϱ���Ϊ�������н�������������Ѻע����еĽ���
// �е��ۻ������н����ʣ�����ʱ������������ǰ��Ӯ�
// �Լ�����ʦ�鿴״̬����ֵ���Լ�������������ʱ��Ҫ����ʱ������

	string winner="not";
// �˱����ж�����Ƿ��н���

	me = this_player();

	s_qian = present("silver_money", me);
	g_qian=present("gold_money",me);

	s_jj= new("/clone/money/silver");
	g_jj= new("/clone/money/gold");

	if (time()-query_temp("playtime")<2)
	return notify_fail("��һ�ָ��꣬��û��ԭ�ء�\n");

// ���û����Ҳû�ƽ𣬲�����Ϸ��
	if(!s_qian && !g_qian)
	return notify_fail("��ҡ����1000���Ĵ󽱣�������ϧ��ûǮѺ��\n");

// ���漴����ʼ��Ϸ����Ϸ��ʽ��Ϊ����ʼ��Ϸ�������н��Ż����ҵ�Ѻע
// ���Ǯ�����н������ÿۣ�ֱ�Ӹ�Ǯ����Ȼ�������Ѿ���Ӧ���٣���

// �����ֱ�����롰games����������������жϡ�
	if(!arg)
	{
		plerbet=5;

// ����������û�����ӣ�һ��Ҫ����䣬��Ȼ���д��󣩻������ٹ�Ѻע�����лƽ��жϣ�
// ���Ҳû�лƽ𣬲�����Ϸ������У����Կ�ʼ��Ϸ������ʱ����Ǯ��
		if(!s_qian || (int)s_qian->query_amount() < plerbet)
		{
			if(!g_qian) return notify_fail("��ҡ����1000���Ĵ󽱣�������ϧ�㲻��Ǯ��ûѺ�ϡ�\n");
		}
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
		if(!s_qian || (int)s_qian->query_amount() < plerbet)
		{
			if(!g_qian) return notify_fail("��ҡ����1000���Ĵ󽱣�������ϧ�㲻��Ǯ��ûѺ�ϡ�\n");
		}
	}


// ����Ϸ�����ۼ�һ�Σ��ۻ����ۼ�Ѻע���1/5����ʷ�ۻ����ۼ�ͳ�ơ�
	t_playtimes++;
        leiji+=(plerbet/10);
        t_leiji+=(plerbet/10);

	message_vision("\n"HIG"$N�ͳ�Ǯ��������һ��������ϣ����������ҡ�ˡ�"NOR"\n",me);

// ����һЩ����ۿ���Ϸ��Ѻע����������ļ��㣬����������ɻƽ����
	if(t_bets>99)
	{
		tempp=(t_bets/100);
		tempq=(t_bets-tempp*100);
		t_bets=tempq;
		t_betg+=tempp;
	}

	if(t_wins>99)
	{
		tempp=(t_wins/100);
		tempq=(t_wins-tempp*100);
		t_wins=tempq;
		t_wing+=tempp;
	}

        win_lose=((t_wing-t_betg)*3);

// ��ؼ��ĵط��������������ֵ�����������ʵĴ�С������

	if(!me->query_temp("lucky/duchang"))
		nowrandom=(200+level+win_lose+plerbet+random(plerbet/2));
	else
nowrandom=(200-(int)me->query_temp("lucky/duchang")+level+plerbet+win_lose+random(plerbet/2));

	games=(random(nowrandom));
	if(wizardp(me)) write("���ڵ�������������ǣ� "+nowrandom+"������ֵ�ǣ� "+games+" .\n");

// ����ҡ���жϡ�

// ������������������������������  ��ʼ�����н��ж�  ����������������������������������

	if(games > 70 && games < 100)
	{
		tell_object(me,"��ҡ���ˣ�"HIM"�I"NOR"\n"),
		peilv = 2;
		winner="yes";
		tell_room(environment(me),(string)me->query("name") + "���˸���С�Ľ���\n",me);
	}

	if(games < 10)
	{
		tell_object(me,"��ҡ���ˣ�"HIM"��"NOR"\n"),
		peilv = 4;
		winner="yes";
		tell_room(environment(me),(string)me->query("name") + "���˸��ڶ�С�Ľ���\n",me);
	}

	if(games == 16 || games == 17 || games == 18 || games == 19)
	{
		tell_object(me,"��ҡ���ˣ�"HIM"��"NOR"\n"),
		peilv = 9;
		winner="yes";
		tell_room(environment(me),(string)me->query("name") + "���˸����Ƚ���\n",me);	
	}

	if(games == 21 || games == 22 || games == 23)
	{
		tell_object(me,"��ҡ���ˣ�"HIM"��"NOR"\n"),
		peilv = 14;
		winner="yes";
		tell_room(environment(me),(string)me->query("name") + "���˶��Ƚ�������\n",me);	
	}

	if(games == 24 || games == 25)
	{
		tell_object(me,"��ҡ���ˣ�"HIM"��"NOR"\n"),
		peilv = 19;
		winner="yes";
		tell_room(environment(me),(string)me->query("name") + "���˴󽱣�����\n",me);	
	}

	if(games == 28 && random(100) == 25)
	{
		tell_object(me,"��ҡ���ˣ�"HIR"��"NOR"\n"),
		peilv = 99;
		winner="yes";
		tell_room(environment(me),"�ۣ�����" + (string)me->query("name") + "������ߵĽ������\n",me);
		CHANNEL_D->do_channel(me, "rumor", sprintf(""HIY"%s����100������Ϸ�󽱣�"NOR"", me->query("name")));
		CHANNEL_D->do_channel(me, "rumor*", "yeah");
	}

// ������������������������������  �н��жϵ������  ������������������������������

// ����������񣬱������ڵ��ۻ��󽱡��������ʦ��Ҳ������ʷ�ۻ��󽱡�

	if(wizardp(me)) write("��ǰ�ۻ����� "+leiji+"��������ʷ�ۻ����� "+t_leiji+"������\n");
	else write("���ڵ��ۻ���Ϊ�� "+leiji+" ��������\n");

// �������н��ˣ��Ƚ����Ƿ����ۻ��󽱵��жϣ�����������

	if(winner=="yes")
	{
		if(peilv==99) tell_object(me,""HIG"���˴󽱣�����������100������̫�����ˣ�"NOR"\n");
		else tell_object(me,""HIG"�н��ˣ�"+(peilv+1)+"����"+(plerbet*(peilv+1))+"�����ӣ�����"NOR"\n");

// ��ʼ�ж��Ƿ����ۻ��󽱣������ۻ��󽱵��Ѷ���Ѻע���е���ϵ��������������˵��
// Ѻע��Խ���н�����ԽС�㡣
		if(random(100+plerbet) == 88)
//		if(random(5)== 3)  // �����ǲ����õġ�
		{
			if(plerbet==5) leiji_jjout=(leiji/10);
			if(plerbet==10) leiji_jjout=(leiji/5);
			if(plerbet==20) leiji_jjout=(leiji*2/5);
			if(plerbet==30) leiji_jjout=(leiji*3/5);
			if(plerbet==50) leiji_jjout=(leiji);

// ����Ҫ��������ǰ�ۻ����𡱵�ֵ��
			leiji-=leiji_jjout;

			tell_object(me,""HIR"�������ۻ��󽱣���������Ϊ "+leiji_jjout+" ������������"NOR"\n");

// �����ۻ���ʱ��ҥ��Ƶ���ᱨ��������ɫ��Ϊ��ȷ����ϵͳ��˵���Ӷ�һ�䡰yeah������
// Ϊ�˷�ֹ���������λᱻϵͳ�ԡ���ͬ�Ļ���Ҫ˵�������˵��������

			CHANNEL_D->do_channel(me, "rumor", sprintf(HIG"%s����"+leiji_jjout+"�����ӵ��ۻ���Ϸ����"NOR, me->query("name")));
			CHANNEL_D->do_channel(me, "rumor*", "yeah");
  // log �ļ���¼��
                  log_file("duchang/DJ_GAME", sprintf("%s(%s)��%s��һ�ŵ�����Ϸ����ۻ��� %d ��������\n",
                  me->query("name"), getuid(me), ctime(time()), leiji_jjout));
		}

// �����жϣ��������ۻ�������ô�����и���ǰ�н�ֵ��leiji_jjout������û�У���ֵĬ��Ϊ0��


// ������㣬�ܹ��г��Ľ���(jjout)�ǣ����Ѻע��(plerbet)��������(peilv)�ټ�����
// ���ۻ������(leiji_jjout)��������һ�ε��ۻ�����û�У����leiji_jjout��ֵ��Ϊ0��

		jjout=(plerbet*peilv+leiji_jjout);

// ���������99�����ӣ���֧����Ӧ�����Ļƽ�
// Ϊ�˱���ϵͳ������ǡ������������������ʱ��֧����Ӧ�Ļƽ�֮�⣬����
// ����һ�����ӡ�
		if(jjout>99)
		{
			tempa=(jjout/100);
			tempb=(jjout-tempa*100);
			if(tempa>99)
			{
				if( (me->query("balance") + tempa*10000) >=10000000)
				{
					write("��Ĵ���ʺ����������ڰ��ֽ�֧�����㡣\n");
					g_jj->set_amount(tempa);
					g_jj->move(me);
				}

                                  else
                                  {
                                          me->add("balance",tempa*10000);
                                     write("�������ۻ��󽱣���ֱ��ת�����Ǯׯ�ʺ��\n");
                                  }
			}
			else
			{
				g_jj->set_amount(tempa);
				g_jj->move(me);
			}
			if(tempb==0) tempb=1;
			s_jj->set_amount(tempb);
		}

		else s_jj->set_amount(jjout);

// ��������ͳ�ƣ���λΪ���ӣ���
		t_wins+=jjout;

// ����æʱ�����أ�����������
		s_jj->move(me);
		set_temp("playtime",time());
		return 1;
	}

// �����н��жϽ���������������Ĳ��н���������

	switch(random(15))
	{
		case 0 :
	tell_object(me,""HIG"��ҡ���ˣ��� ��û���н���"NOR"\n");
		break;

		case 1 :
	tell_object(me,""HIG"��ҡ���ˣ��� ��û���н���"NOR"\n");
		break;

		case 2 :
	tell_object(me,""HIG"��ҡ���ˣ��� ��û���н���"NOR"\n");
		break;

		case 3 :
	tell_object(me,""HIG"��ҡ���ˣ��� ��û���н���"NOR"\n");
		break;

		case 4 :
	tell_object(me,""HIG"��ҡ���ˣ��� ��û���н���"NOR"\n");
		break;

		case 5 :
	tell_object(me,""HIG"��ҡ���ˣ��� ��û���н���"NOR"\n");
		break;

		case 6 :
	tell_object(me,""HIG"��ҡ���ˣ��� ��û���н���"NOR"\n");
		break;

		case 7 :
	tell_object(me,""HIG"��ҡ���ˣ��� ��û���н���"NOR"\n");
		break;

		case 8 :
	tell_object(me,""HIG"��ҡ���ˣ��� ��û���н���"NOR"\n");
		break;

		case 9 :
	tell_object(me,""HIG"��ҡ���ˣ��� ��û���н���"NOR"\n");
		break;

		case 10 :
	tell_object(me,""HIG"��ҡ���ˣ��� ��û���н���"NOR"\n");
		break;

		case 11 :
	tell_object(me,""HIG"��ҡ���ˣ��� ��û���н���"NOR"\n");
		break;

		case 12 :
	tell_object(me,""HIG"��ҡ���ˣ��� ��û���н���"NOR"\n");
		break;

		case 13 :
	tell_object(me,""HIG"��ҡ���ˣ��� ��û���н���"NOR"\n");
		break;

		case 14 :
	tell_object(me,""HIG"��ҡ���ˣ��� ��û���н���"NOR"\n");
		break;
	}

// ��Ϸû�н�����ʼ������ҵ�Ǯ��

// ���û���ӻ����Ӳ���������1���ƽ𣬲�������Ӧ���ӡ�
	if(!s_qian || (int)s_qian->query_amount() < plerbet)
	{
		g_qian->add_amount(-1);
		if(!s_qian)
		{
			s_jj->set_amount(100-plerbet);
			s_jj->move(me);
		}
		else s_qian->add_amount(100-plerbet);
	}

// ����ֱ�ӿۡ�
	else s_qian->add_amount(-plerbet);

// ��Ѻעͳ�ơ�
	t_bets+=plerbet;

	set_temp("playtime",time());
	return 1;
}

