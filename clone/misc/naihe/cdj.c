//                ��׼��������ʾ��                                   |

/*********************************************************************
 ���䣬�������ĳ��ľ�����Ϸ��  ��adj.c or bdj.c or cdj.c
 by naihe  2002-04-23  ��ï��
 naihe ��2002-05-17�����޸����Ʊ��ļ�
 02-05-18�����޸ģ���ֱ����Ѫ������ �汾3.0~~
 02-05-20 �Ӹ����ϸ��������ʷ�ʽ�����ڲ�����Ǯ��Ҳ����Ӯ��ҵ�Ǯ����
 02-06-25 �汾4.0 ����֮ǰ�Ĵ���ͬ�ˣ�

 �ĳ�����Ϸ���ʾ������ϸ���ԣ��޸ı��ļ����ʵȴ��������أ�
 ���ļ���ԭdc_dating.c �ı������

 ����޸�ʱ�䣺15:05 02-6-25    by naihe

call naihe->set_temp("seesee",1) ,�����ſ��Բ鿴ĳ������Ϸ״̬���档
*********************************************************************/

#include <ansi.h>
inherit ROOM;

int t_playtimes,t_bets,t_betg,t_wins,t_wing,leiji,t_leiji,level,t_peilv,
level=1;
// ���ϱ����ֱ��ǣ�
// ����Ϸ�������ܰ���Ѻע��ܻƽ�Ѻע��ܰ����н������ܻƽ��н�����
// ��ǰ�ۻ�������ʷ�ۻ����𣬵�ǰ��Ϸ�Ѷȡ�

string games_now="open";


void create()
{

//        set("short", HIB"һ��С����"NOR);

//	set("short", HIG"����С����"NOR);

      set("short", HIC"����С����"NOR);

	set("long", "����һ��С���䣬�����м���������������ʹ��������˿����������ͦ
�ľ��ģ������������������Ϸ�ˡ�����ֻ����һ��������jiqi�������������
������ͬ���������ص������ ���ۻ����˽��ء� ���㲻��ԾԾ���ԡ�\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up","1");
	set("invalid_startroom",1);

	set("item_desc",([
	    "jiqi":"������д������˵����Ĭ��ÿ��5������������(games)������Ϸ����Ҫ��ע������:
games a--10��������games b--20������,games c--30��������games yeah--50��������
���룺cktop �����Բ�ѯ���ڵġ��ۻ����˽��ء����ۻ���\n"HIR"��ʦ���� mewiz <open/close> ���Ż�رձ���Ϸ��\n�� xxx <easy/hard/pro> �趨��Ϸ�Ѷȣ�ʡ�Բ�������ʾ��ǰͳ�����ݡ�"NOR"\n",
	]));

	set("exits", ([
	    "out":__DIR__"dc_tongdao",
	    ]));

	setup();
}

void init()
{
	if (wizardp(this_player()))
	{
	    add_action("do_xxx", "xxx");
	    add_action("do_mewiz","mewiz");
	}
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
	write("���ڵġ��ۻ����˽��ء����ܽ��Ϊ�� "+leiji+" ��������\n");
	write("���Ѻע��������ܹ��õ����ٷݶ�ġ��ۻ����˽��ء��ڵĽ���
<games> 10% ��<games a> 20% ��<games b> 40% ��<games c> 60% ��<games yeah> 90%.\n");
	return 1;
}

int do_xxx(string arg)
{
	if(!arg)
	{
		int temps,tempg;
		temps = (t_bets-t_wins);
		tempg = (t_betg-t_wing);
     		write(""HIY"��Ϸ������"+t_playtimes+ "��  ���룺"+tempg+" �� "+temps+" �� �����ڵ��Ѷ�Ϊ "+level+".\n��Ѻע��"+t_betg+" �� "+t_bets+" ��  �ܽ���"+t_wing+" �� "+t_wins+" ���� �������ӵ��Ѷ�ֵ�ǣ�"+(int)((t_wing-(t_peilv/100))*2)+" .\n��ʷ�ۻ����ܶ�Ϊ�� "+t_leiji+" ��  ��ǰ�ۻ��󽱣� "+leiji+ " ����"NOR"\n");
	}

	if(arg=="easy") level=1;
	if(arg=="hard") level=21;
	if(arg=="pro") level=51;

	if(arg && arg!="easy" && arg!="hard" && arg!="pro") write("ָ���ʽ��<xxx easy/hard/pro>\n");

	if(arg) write("now level is: "+level+" .\n");
	return 1;
}

int do_mewiz(string arg)
{
	object me=this_player();

	if(!arg || (arg!="open" && arg!="close")) return notify_fail("��ʽ��mewiz <open/close> ����/�رձ���Ϸ��\n");

	if(arg==games_now) return notify_fail("�����Ѿ���"+games_now+"��״̬�ˡ�\n");

	games_now=arg;
	if(games_now=="open") message_vision(HIW"$N���Ļ������������������ˣ�������¿�������Ϸ��\n"NOR,this_player());
	if(games_now=="close") message_vision(HIW"$N���Ļ�������������֪��ô�Ļ��ˣ�ֻ�ð���Ϸ�ر��ˡ�\n"NOR,me);
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

// ��������������������������������������������������
// �������������� ��ʼ������Ϸ������ ����������������
// ��������������������������������������������������

int do_games(string arg)
{
	object s_qian,g_qian,s_jj,g_jj,me;
// ���ϱ���Ϊ��������ϵİ�����������ϵĻƽ�ϵͳ���õİ�����ϵͳ���õĻƽ��Լ�me.

	int games,plerbet,jjout,leiji_jjout,peilv,tempa,tempb,
win_lose,nowrandom,tempp,tempq,temp_allbet,temp_allwin;
// ���ϱ���Ϊ�������н�������������Ѻע����еĽ���
// �е��ۻ������н����ʣ�����ʱ������������ǰ��Ӯ�
// �Լ�����ʦ�鿴״̬����ֵ���Լ��ĸ���������ʱ��Ҫ����ʱ������

	string winner="not";
// �˱����ж�����Ƿ��н���

	if(games_now!="open") return notify_fail(HIR"�����Ѿ����ˣ������������ء�\n"NOR);
// �˴�������ʦ������Ϸ�Ƿ񿪷š�

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

	if(t_playtimes==1)
	    log_file("duchang/DJ_GAME", sprintf("\n%s�����ˣ���%s��%s(%s)��ʼ�˵�һ����Ϸ��\n",this_object()->query("short"),ctime(time()),me->query("name"), getuid(me)));

	leiji+=(plerbet/5);
	t_leiji+=(plerbet/5);

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

// ��������������������������������������������������
// ���������� ����һ���Ƿǳ��ؼ���һ���ط� ����������
// ��������������������������������������������������

	win_lose=((t_wing-(t_peilv/100))*2);

	if(!me->query_temp("duchang/lucky"))
		nowrandom=(250+level+win_lose+plerbet);  //+random(plerbet/2)
	else
nowrandom=(250-(int)me->query_temp("duchang/lucky")+level+plerbet+win_lose);

// +random(plerbet/2)

// ���������ж�ʽ��ȥ�������Ѻע��С���Ѷȱ仯��ԭ����������ѹ��Խ���Խ�ѵġ�

	games=(random(nowrandom));

	temp_allbet=(t_betg*100+t_bets);
	temp_allwin=(t_wing*100+t_wins);


	if(wizardp(me))
	{
		tell_object(me,HIW"��"+t_playtimes+""NOR+HIY" ��"+(t_betg*100+t_bets)+" ��Ч��"+t_peilv+""NOR+HIR" ��"+(t_wing*100+t_wins)+" ����"+win_lose+""NOR+HIC" ��"+((t_betg*100+t_bets)-(t_wing*100+t_wins))+""NOR+HIM" ����"+nowrandom+""NOR+HIW" �ܻ�"+t_leiji+" �ֻ�"+leiji+" "NOR);  // ��������ǲ�Ҫ\n���еģ����������ˡ�

		if(temp_allbet - temp_allwin > (leiji/3))
		    write(HIY"�ɳ�\n"NOR);
		else write(HIB"����\n"NOR);
	}		

// ��������������������������������������������������
// ������ �����Ǽ��㱾����Ϸ���Ѷȵģ��ǳ��ؼ� ������
// ��������������������������������������������������

// ����ҡ���жϡ�

// ��������������������������������������������������
// ���������������� ��ʼ�����н��ж� ����������������
// ��������������������������������������������������

	if(games > 70 && games < 100)
	{
		tell_object(me,"��ҡ���ˣ�"HIM"�I"NOR"\n"),
		peilv = 2;
		winner="yes";
		tell_room(environment(me),(string)me->query("name") + "���˸���С�Ľ���\n",me);
	}

	if(games < 12)
	{
		tell_object(me,"��ҡ���ˣ�"HIM"��"NOR"\n"),
		peilv = 4;
		winner="yes";
		tell_room(environment(me),(string)me->query("name") + "���˸��ڶ�С�Ľ���\n",me);
	}

	if(games==16 || games==17 || games==18 || games==19)
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

	if(winner!="yes" &&  (t_betg-t_wing) >5 && leiji > (plerbet*5))
	{
		if(getuid(me)=="naihe" && (int)me->query_temp("seesee")==1 )
			write(HIW"�����л���õ��������ͽ���\n"NOR);

		if(random(50)==24)
		{
			message_vision(HIY"$N�����������ͽ���\n$N���õ��ڡ��ۻ����˽��ء���֧���ģ�������Ѻע�Ľ���5���Ľ��� ��"+(plerbet*5)+"�����ӣ�\n"NOR,me);

			leiji-=(plerbet*5);
			peilv = 4;
			winner="yes";
		}
	}

// ��������������������������������������������������
// �������������� �����н��жϵ������ ��������������
// ���������������� ��ʼ�ۻ����ж� ����������������
// ��������������������������������������������������

// ����������񣬱������ڵ��ۻ��󽱡��������ʦ�������˱���һ�䣨��Ϊ�������ˣ�

	if(!wizardp(me)) write("���ڵġ��ۻ����˽��ء����ܽ��Ϊ�� "+leiji+" ��������\n");

// �������н��ˣ��Ƚ����Ƿ����ۻ��󽱵��жϣ�����������

// �κ���Ҫ�鿴����ı��棬���������ָ�call naihe->set_temp("seesee",1)

	if(getuid(me)=="naihe" && (int)me->query_temp("seesee")==1 )
	{
		if(temp_allbet - temp_allwin > (leiji/3))
		    write(HIY"ͨ���ˡ�"+temp_allbet+" - "+temp_allwin+" = "HIW""+(temp_allbet - temp_allwin)+" > "+(leiji/3)+""NOR+HIY" �������� - ����� > ��ǰ�ۻ���������һ��\n"NOR);
		else
		    write(HIR"��ͨ����"+temp_allbet+" - "+temp_allwin+" = "HIW""+(temp_allbet - temp_allwin)+" < "+(leiji/3)+""NOR+HIR" �������� - ����� < ��ǰ�ۻ���������һ��\n"NOR);
	}

	if(winner=="yes")
	{
		if(peilv==99) tell_object(me,""HIG"���˴󽱣�����������100������̫�����ˣ�"NOR"\n");
		else tell_object(me,""HIG"�н��ˣ�"+(peilv+1)+"����"+(plerbet*(peilv+1))+"�����ӣ�����"NOR"\n");

// ��ʼ�ж��Ƿ����ۻ��󽱣������ۻ��󽱵��Ѷ���Ѻע���е���ϵ��������������˵��
// Ѻע��Խ���н�����ԽС�㡣

		if((temp_allbet - temp_allwin) > (leiji/3) && (random(80+plerbet) == 44))
		{
			if(plerbet==5) leiji_jjout=(leiji/10);
			if(plerbet==10) leiji_jjout=(leiji/5);
			if(plerbet==20) leiji_jjout=(leiji*2/5);
			if(plerbet==30) leiji_jjout=(leiji*3/5);
			if(plerbet==50) leiji_jjout=(leiji*9/10);

// ����Ҫ��������ǰ�ۻ����𡱵�ֵ��
			leiji-=leiji_jjout;

			tell_object(me,""HIR"�������ۻ��󽱣���������Ϊ "+leiji_jjout+" ������������"NOR"\n");

// �����ۻ���ʱ��ҥ��Ƶ���ᱨ��������ɫ��Ϊ��ȷ����ϵͳ��˵���Ӷ�һ�䡰yeah������
// Ϊ�˷�ֹ���������λᱻϵͳ�ԡ���ͬ�Ļ���Ҫ˵�������˵��������

			CHANNEL_D->do_channel(me, "rumor", sprintf(HIG"%s����"+leiji_jjout+"�����ӵ��ۻ���Ϸ����"NOR, me->query("name")));
			CHANNEL_D->do_channel(me, "rumor*", "yeah");

// log �ļ���¼��
	log_file("duchang/DJ_GAME", sprintf("%s(%s)��%s��%s�ĵ�%d����Ϸ���ۻ��� %d ��.\n",me->query("name"),getuid(me),ctime(time()),this_object()->query("short"),t_playtimes,leiji_jjout));

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
					write("�����ˡ��ۻ����˽��ء��ڵ����˽��𣬽�ֱ��ת�����Ǯׯ�ʺ��\n");
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

// ��������������������������������������������������
// �������� ������û���е����л����еð�ο�� ��������
// ��������������������������������������������������

	if(leiji>=100 && random(100)>=95)
	{
		message_vision(HIY"$N�������˰�ο����\n$N���õ��ڡ��ۻ����˽��ء���֧���ģ�������Ѻע�Ľ��"+plerbet+"�����ӡ�\n"NOR,me);

/*
		jjout=(plerbet/5);
		if(!s_qian)
		{
			s_jj->set_amount(jjout);
			s_jj->move(me);
		}
		else s_qian->add_amount(jjout);

		t_wins+=jjout;
		leiji-=((plerbet/5)*2);
*/		

		leiji-=plerbet;

		set_temp("playtime",time());
		return 1;
	}

// ��������������������������������������������������
// �������� ʲô�������У��۵����Ѻע���Ǯ ��������
// ��������������������������������������������������

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

	t_peilv+=((plerbet*8)/10); // ����һ���ǳ���Ҫ�ı�����

	set_temp("playtime",time());
	return 1;
}
