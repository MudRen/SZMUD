//                ��׼��������ʾ��                                   |
// �ĳ�����ս����Ϸ��һ������˫�˰桰����ս��֮������ dc_fight.c
// by naihe ��ï��   2002-06-22ʼ����2002-06-22 ������ɣ�����

/*****************************************************

�жϷ�ʽд���൱������

*****************************************************/

#include <ansi.h>
inherit ROOM;

string last_winner,last_loser,games,temp_winner,attacker,
plera_name,plerb_name,plera_id,plerb_id,ause,buse,
games="free",
plera_id="no",
plerb_id="no";

int last_bet,t_times,t_bets,now_bet,now_time,a_sword,b_sword,
a_hp,b_hp,a_gjl,b_gjl,a_busy,b_busy,a_power,b_power,
atk_timesa,atk_timesb;

string look_pai();
void games_free();
void times();
void halt();
void check_hp();

void atk_k();
void atka_killa();
void atkb_killa();
void ause_free();
void buse_free();
void check_sword();

void create()
{
	set("short", HIG"������Ϸƫ��"NOR);
	set("long", "������������Ϸƫ�������䲼�úͶ��ߵĴ�������һģһ����Ҳ������λ��
���˸���̨��̨������һ���������ӣ�pai����\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);
	set("no_clean_up",1);
	set("item_desc",([
	    "pai":(: look_pai :),
	]));

	set("exits", ([
	    "east" : __DIR__"dc_kill",
	    ]));

	setup();
}

void init()
{
	add_action("do_skills",  "exercise");
	add_action("do_skills",  "dazuo");
	add_action("do_skills",  "respirate");
	add_action("do_skills",  "tuna");
	add_action("do_skills",  "practice");
	add_action("do_skills",  "lian");
	add_action("do_study",  "study");
	add_action("do_study",  "du");
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_food", "drink");
	add_action("do_food", "he");
	add_action("do_yun","yun");
	add_action("do_chang","chang");
	add_action("do_start","start");
	add_action("do_kk","kk");
	add_action("do_xxx","xxx");

	if(wizardp(this_player()))
	{
		add_action("do_mewiz","mewiz");
		add_action("do_outhere","goto");
		add_action("do_outhere","home");
	}
}

void reset() 
{ 
              ::reset(); 
              set("no_clean_up", 1); 
} 

string look_pai()
{
	message_vision(CYN"$N�������Ͽ�ȥ��һ����Ȼ��������ӡ�\n"NOR,this_player());
	return "
��������������������������������������������������������������������
                       "HIG"˫������ս����Ϸ˵��"NOR"

    ����Ϸ����λ���ͬʱ���У�ģ������ս������ʽ���ڹ涨ʱ�����ܹ�
�ѶԷ��򵹣�������ʱ���������Ϣ���߽����ʤ��������ʱ��Ҫ����2����
��ʤ���߽��ɵõ�����Ѻע����Ϸָ���У�
"HIY"
start , kk <k / up / heal / killa / killb / killc> "NOR", �Լ���ѯ��¼��
ָ�� "HIY"xxx"NOR" .

    �ڴ��ƽ�ֵ�ʱ�򣬱�ϵͳ������ȡÿ��1 �����������ã����������
�շѡ�

    ף��λ��ÿ��ģ� :)

                                    "HIG"--by naihe  2002-06-22"NOR"
��������������������������������������������������������������������\n";
}

int outhere()
{
	if(this_player()->query_temp("duchang/fighting"))
	{
		write("�㻹����Ϸ�أ���ô�ܵ�����Ҫ����Ϸ��BUG����\n");
		return 1;
	}
	return 0;
}

int do_mewiz(string arg)
{
	if(!arg || (arg!="free" && arg!="close")) return notify_fail("��ʽ��mewiz <free/close> ���Ż�رձ���Ϸ��\n");
	
	if(arg=="free")
	{
		if(games!="close") return notify_fail("��Ϸ���������������ء�\n");
		message_vision(HIW"$Nվ����̨���������˼������Χ��̨�ߵ�Ũ����ɢ���ˡ�\n"NOR,this_player());
		games="free";
		return 1;
	}
	if(arg=="close")
	{
		if(games=="close") return notify_fail("��Ϸ�Ѿ��ǹرյ��ˡ�\n");
		if(games!="free") return notify_fail("Ҫ�ر���ϷҲ�ܵ�����������һ�ְɣ�\n");
		message_vision(HIW"$Nվ����̨���������˼������ֻ��̨��Ũ�����𣬰���̨Χ��������\n"NOR,this_player());
		games="close";
	}
	return 1;
}

int do_xxx()
{
	write("\n���һ���� "HIG""+last_winner+""NOR" սʤ�� "HIG""+last_loser+""NOR" ���ʽ�Ϊ "HIG""+last_bet+""NOR" ���ƽ�\n����Ϸ������"HIG""+t_times+""NOR" �ܽ�������"HIG""+t_bets+""NOR" ���ƽ�\n");
	return 1;
}

int do_yun()
{
	if(random(3)>0)
	{
		write("ר�Ĵ�ܣ�ĪҪ���ҡ�\n");
		return 1;
	}
	return 0;
}

int do_chang()
{
	write("ר�Ĵ�ܣ�ĪҪ���ҡ�\n");
	return 1;
}

int do_food()
{
	write("�Ժ��뵽��¥������\n");
	return 1;
}

int do_skills()
{
	write("��������������������Ϸ�ļ����ء�\n");
	return 1;
}

int do_study()
{
	write("���飿��������ϸ������Ϸ��˵���ء�\n");
	return 1;
}

int do_start(string arg)
{
	object me,qian;
	string temp;

	me=this_player();
	qian=present("gold_money",me);

	if(games=="close") return notify_fail("����Ϸ���ڲ����ţ������������\n");
	if(games!="free" && games!="wait")
		return notify_fail("������������Ϸ�����Ժ����ԡ�\n");
	if(games=="free")
	{
		if (!arg || sscanf(arg, "%d %s", now_bet ,temp) !=2)
		return notify_fail("������Ϸָ���ʽ�� start <����> <���ҵ�λ>   ���磺start 1 gold \n");

		if(temp!="gold") return notify_fail("����ֻ���ܻƽ�Ķ�ע��\n");
		if(now_bet<2 || now_bet>100)
			return notify_fail("�Ľ�Ѻע��Χ�� 2-100 ���ƽ�\n");
		if(!qian || (int)qian->query_amount() < now_bet)
			return notify_fail("�����Ǯ����������ʡʡ�ɡ�\n");
		qian->add_amount(-now_bet);
		me->set_temp("duchang/fighting",1);
		message_vision(sprintf(HIW"\n$N�ó�%s���ƽ���̨��һ�ף�����˵������˭�������ұ�һ�֣���\n\n"NOR,chinese_number(now_bet)),me);
		games="wait";
		tell_object(me,"��ȴ�20���ñ����Ҽ��롣\n");
		message("vision","��ҪӦս��ֱ������ start ���ɣ�\n", environment(me),me);
		plera_name=me->query("name");
		plera_id=me->query("id");
		call_out("games_free",20);
		return 1;
	}

	if(games=="wait")
	{
		if(me->query("id")==plera_id)
			return notify_fail("���Ѿ����µ������ˣ����ĵȵȰա�\n");
		if(!qian || (int)qian->query_amount() < now_bet)
		{
		    message_vision(CYN"$N�����е������Ҳ��ǲ��ң���ֻ��û��Ǯ����\n"NOR,me);
		    return 1;
		}
		plerb_id=me->query("id");
		plerb_name=me->query("name");
		games="wait_start";
		me->set_temp("duchang/fighting",1);
		message_vision(HIW"\n$NҲ�ͳ���һЩ�ƽ���̨��һ�ף�����˵���������������һ�֣���\n\n"NOR,me);
		qian->add_amount(-now_bet);
		message("vision",HIW"ֻ������ͬʱ������̨������������ʼ�ˣ�\n"NOR,this_object());
// �����¼�ļ���
		t_times++;
		t_bets+=now_bet;
	        log_file("duchang/FIGHT_GAME", sprintf("%s(%s) VS %s(%s)��%s ��%d gold ��ע��\n",
                plera_name,plera_id,plerb_name,plerb_id,ctime(time()),now_bet));
		call_out("times",3);
		return 1;
	}
	return 1;
}

void games_free()
{
	object duzhu,tempa,tempb,ob;

	ob=this_object();
	duzhu=new("/clone/money/gold");
	tempa=find_player(plera_id);
	if(plerb_id!="no") tempb=find_player(plerb_id);
	if(games=="fighting" || games=="wait_start") return;
	if(games=="wait")
	{
		if(!tempa) message("vision",""HIW""+plera_name+"���»ƽ����ս�֣��Լ�ȴ͵͵����ˡ�\n"NOR,ob);
		else
		{
		    message_vision(HIW"$N����һ���Բ�������Ӧս��ʧ���ذѻƽ�����������\n"NOR,tempa);
		    duzhu->set_amount(now_bet);
		    if(!present("gold_money",tempa)) duzhu->move(tempa);
		    else present("gold_money",tempa)->add_amount(now_bet);
		    tempa->delete_temp("duchang/fighting");
		}
	}

	if(games=="finish")
	{
		if(now_time<=0) message("vision",HIW"\nʱ�䵽���������Խ����ˡ�\n"NOR,ob);
		else message("vision",HIW"\n���˵����ˣ��������Խ�����\n"NOR,ob);

		if(temp_winner==plera_id)
		{
		    message("vision",HIW"���α��Ե�ʤ������"+plera_name+"����������еĶĽ�\n\n"NOR,ob);
		    last_winner=plera_name;
		    last_loser=plerb_name;
		    last_bet=now_bet;
		    log_file("duchang/FIGHT_GAME", sprintf("%s(%s) ��ʤ��\n\n",plera_name,plera_id));
		    duzhu->set_amount(now_bet*2);
		    if(!present("gold_money",tempa)) duzhu->move(tempa);
		    else present("gold_money",tempa)->add_amount(now_bet*2);
		}

		if(temp_winner==plerb_id)
		{
		    message("vision",HIW"���α��Ե�ʤ������"+plerb_name+"����������еĶĽ�\n\n"NOR,ob);
		    last_winner=plerb_name;
		    last_loser=plera_name;
		    last_bet=now_bet;
		    log_file("duchang/FIGHT_GAME", sprintf("%s(%s) ��ʤ��\n\n",plerb_name,plerb_id));
		    duzhu->set_amount(now_bet*2);
		    if(!present("gold_money",tempb)) duzhu->move(tempb);
		    else present("gold_money",tempb)->add_amount(now_bet*2);
		}

		if(temp_winner=="none")
		{
		    if(a_hp>0 || b_hp>0) message("vision",HIW"���α���˫��ʣ����Ϣֵһ��������ʤ����\n�Ľ�����λ����ȡ�ء�\n"NOR,ob);
		    else message("vision",HIW"���˶������ˣ����Բ���ʤ�����Ľ�����λ����ȡ�ء�\n"NOR,ob);
		    message("vision",HIW"��ϵͳ����ȡÿλһ���ƽ�������ѡ�\n\n"NOR,ob);
		    log_file("duchang/FIGHT_GAME", sprintf("����ʤ����\n\n"));
		    now_bet--;
		    duzhu->set_amount(now_bet);
		    if(!present("gold_money",tempa)) duzhu->move(tempa);
		    else present("gold_money",tempa)->add_amount(now_bet);
		    if(!present("gold_money",tempb)) duzhu->move(tempb);
		    else present("gold_money",tempb)->add_amount(now_bet);
		}
	}
	if(tempa) tempa->delete_temp("duchang/fighting");
	if(tempb) tempb->delete_temp("duchang/fighting");
	games="free";
	plera_id="no";
	plerb_id="no";
	plera_name="none";
	plerb_name="none";
	now_bet=0;
}

void times()
{
	object tempa,tempb,ob;

	ob=this_object();
	if(games!="fighting" && games!="wait_start") return;
	tempa=find_player(plera_id);
	tempb=find_player(plerb_id);
	if(!tempa || !tempb)
	{
		halt();
		return;
	}
	if(games=="wait_start")
	{
		message("vision",HIY"������ʼ������\n"NOR,this_object());
		now_time=60;
		games="fighting";
		a_hp=100;
		b_hp=100;
		a_busy=0;
		b_busy=0;
		a_gjl=0;
		b_gjl=0;
		a_sword=100;
		b_sword=100;
		a_power=(5+random(6));
		b_power=(5+random(6));
		temp_winner="no";
		ause="ok";
		buse="ok";
	}
	now_time--;
	if(a_hp<=98) a_hp+=(random(3));
	if(b_hp<=98) b_hp+=(random(3));
	if(a_power<=30 && ause=="ok") a_power+=(random(3));
	else if(a_power<=30) a_power+=(random(2));
	if(b_power<=30 && buse=="ok") b_power+=(random(3));
	else if(b_power<=30) b_power+=(random(2));
	a_busy--;
	if(a_busy<=0) a_busy=0;
	b_busy--;
	if(b_busy<=0) b_busy=0;
	if(now_time<=0)
	{
		games="finish";
		check_hp();
		return;
	}
	tell_object(tempa,HIG"�� "+now_time+" ��"NOR"  �����Ϣ��"HIC""+a_hp+""NOR"/100 ������"HIY""+a_power+""NOR"/30 æʱ��"HIR""+a_busy+""NOR" .\n\n");
	tell_object(tempb,HIG"�� "+now_time+" ��"NOR"  �����Ϣ��"HIC""+b_hp+""NOR"/100 ������"HIY""+b_power+""NOR"/30 æʱ��"HIR""+b_busy+""NOR" .\n\n");

// ������ã���ʹϵͳ����ÿ�غ϶���״̬������Ļ���ҡ�

	if(a_power>=30 && random(3)==1) message_vision(HIC"$N˫Ŀһ���������ʢ���������Ѿ۵����壡\n"NOR,tempa);
	if(b_power>=30 && random(3)==1) message_vision(HIC"$N˫Ŀһ���������ʢ���������Ѿ۵����壡\n"NOR,tempb);

    if(random(5)==1)
    {
	if(a_hp>=100)
		message("vision",HIW"��"+plera_name+"�������������ˡ���\n"NOR,ob);
	if(a_hp>90 && a_hp<100)
		message("vision",HIW"��"+plera_name+"�ƺ����˵����ˣ����������¡���\n"NOR,ob);
	if(a_hp>70 && a_hp<91)
		message("vision",HIW"��"+plera_name+"���˵��ˣ���ʼ�����е�����ˡ���\n"NOR,ob);
	if(a_hp>50 && a_hp<71)
		message("vision",HIW"��"+plera_name+"�˵�������ģ���Ե��е��Ǳ�����\n"NOR,ob);
	if(a_hp>20 && a_hp<51)
		message("vision",HIW"��"+plera_name+"�������أ��Ѿ���Ҫ֧�ֲ�ס�ˡ���\n"NOR,ob);
	if(a_hp>10 && a_hp<21)
		message("vision",HIW"��"+plera_name+"�Ѿ�ͷ���ۻ��Ŀ�Ҫ�����ˡ���\n"NOR,ob);
	if(a_hp>0 && a_hp<11)
		message("vision",HIW"��"+plera_name+"ֻʣ���һ���������ڿ��֧���š���\n"NOR,ob);

	if(b_hp>=100)
		message("vision",HIW"��"+plerb_name+"�������������ˡ���\n"NOR,ob);
	if(b_hp>90 && b_hp<100)
		message("vision",HIW"��"+plerb_name+"�ƺ����˵����ˣ����������¡���\n"NOR,ob);
	if(b_hp>70 && b_hp<91)
		message("vision",HIW"��"+plerb_name+"���˵��ˣ���ʼ�����е�����ˡ���\n"NOR,ob);
	if(b_hp>50 && b_hp<71)
		message("vision",HIW"��"+plerb_name+"�˵�������ģ���Ե��е��Ǳ�����\n"NOR,ob);
	if(b_hp>20 && b_hp<51)
		message("vision",HIW"��"+plerb_name+"�������أ��Ѿ���Ҫ֧�ֲ�ס�ˡ���\n"NOR,ob);
	if(b_hp>10 && b_hp<21)
		message("vision",HIW"��"+plerb_name+"�Ѿ�ͷ���ۻ��Ŀ�Ҫ�����ˡ���\n"NOR,ob);
	if(b_hp>0 && b_hp<11)
		message("vision",HIW"��"+plerb_name+"ֻʣ���һ���������ڿ��֧���š���\n"NOR,ob);

	message("vision","\n",ob);
    }
	call_out("times",1);
}

void check_hp()
{
	if(games=="finish")
	{
		if(a_hp>b_hp) temp_winner=plera_id;
		if(a_hp<b_hp) temp_winner=plerb_id;
		if(a_hp==b_hp) temp_winner="none";
		games_free();
		return;
	}		
	if(a_hp<1 || b_hp<1)
	{
		if(a_hp<1 && b_hp>0) temp_winner=plerb_id;
		if(a_hp>0 && b_hp<1) temp_winner=plera_id;
		if(a_hp<1 && b_hp<1) temp_winner="none";
		games="finish";
		games_free();
		return;
	}
}

void halt()
{
	message("vision",HIW"��֪����˭��Ʒ��ô����Ŵ��ž�Ȼ�ܵ��ˡ�\n������Ϸǿ�Ƚ�������ע��Ϊ�����ѽ���ϵͳ��ȡ��\n"NOR,this_object());
// ��¼����ʷ�ļ���
	log_file("duchang/FIGHT_GAME", sprintf("ĳһ���뿪��MUD����Ϸǿ�Ƚ�����\n\n"));
// ����״̬��
	games="halt";
	games_free();
}

int do_kk(string arg)
{
	object me;
	me=this_player();
	if(games!="fighting") return notify_fail("��Ϸ��û��ʼ�ء�\n");

// ��������������������������������
// �������� ��һ��ҵĳ��� ��������
// ��������������������������������

	if(me->query("id") == plera_id)
	{
		if(!arg) return notify_fail("��ʽ��kk <k / up / heal / killa / killb / killc> \n");
		if(a_busy>0)
		{
			tell_object(me,"�����һ��������û����ɣ�Խ��ֻ��Խ�ң�\n");
			a_busy+=(random(2));
			return 1;
		}
		if(a_power<=0 && arg!="up") return notify_fail("�����������κ���ʽ��\n");

		if(arg=="k")
		{
			if(a_power<2) return notify_fail("��������������\n");
			a_power--;
			a_busy+=(1+random(2));
			a_gjl=(5+random(6));
			attacker="aaa";
			atk_k();
			return 1;
		}

		if(arg=="up")
		{
			if(a_power>=25) return notify_fail("�������������\n");
			if(ause!="ok") return notify_fail("��Ѩ�����⣬�޷�����������\n");
			message_vision(HIC"$N���һ����˫��ͻȻ����һ����ȫ����������ɱ��ɢ�������\n"NOR,me);
			a_power+=(3+random(3));
			a_busy+=(2+random(4));
			return 1;
		}

		if(arg=="heal")
		{
			if(a_hp>=80) return notify_fail("�����ڻ������úܣ�\n");
			if(a_power<10) return notify_fail("����������㣬�޷��ָ���Ϣ��\n");
			message_vision(HIG"$N���������һ���������������ö��ˡ�\n"NOR,me);
			a_hp+=(10+random(11));
			a_power-=(5+random(6));
			a_busy+=(1+random(2));
			return 1;
		}

		if(arg=="killa")
		{
			if(a_power<15) return notify_fail("����������������ʽ��\n");
			if(ause!="ok") return notify_fail("��Ѩ�����⣬�޷�ʩչ������\n");
			message_vision(HIC"\n$N��Хһ��������Ծ�����Ǿ�����̤�������ȡ���\n",me);
			a_busy+=(3+random(3));
			atk_timesa=(((a_power-15)/3)+5);
			a_power=0;
			atka_killa();
			return 1;
		}

		if(arg=="killb")
		{
			if(ause=="ok" && a_power<10) return notify_fail("����������������ʽ��\n");
			if(ause!="ok")
			{
				if(a_power<5) return notify_fail("����������������ʽ��\n");
				a_power-=5;
                                a_busy+=1;
				switch(random(4))
				{
				    case 0:message_vision(HIG"$N����ֱ�屻��Ѩ������Ȼֻ����Ѫ�泩��Ѩ���忪�ˣ�\n"NOR,me);
				    ause="ok";
				    break;
				    default:message_vision(HIY"$N����ֱ�屻��Ѩ����ȴ�޷��⿪���շ�һ��������\n"NOR,me);
				}
				return 1;
			}

			if(buse!="ok") return notify_fail("�Է���Ѩ����û���ء�\n");

			a_power-=10;
			a_busy+=2;
			message("vision",HIB"\n������ǰһ����ֻ��"+plera_name+"ͻȻ���ƹ��ȣ�����ƽ�"+plerb_name+"��ʩչ���ˡ���Ӱ��Ѩ�֡���\n"NOR,this_object(),({me,find_player(plerb_id)}));
			tell_object(me,HIB"\n��˲��ƽ�"+plerb_name+"����Ȼʩչ���ˡ���Ӱ��Ѩ�֡���\n"NOR);
			tell_object(find_player(plerb_id),HIB"\n����ǰһ����ֻ��"+plera_name+"�Ƶ������ǰ����Ȼʩչ���ˡ���Ӱ��Ѩ�֡���\n"NOR);

			switch(random(3))
			{
			    case 0:message_vision(WHT"$N��֮�¼�æ�������������о����գ�\n"NOR,find_player(plerb_id));
			    break;
			    default:message_vision(HIR"$Nһ���ӱ�����Ѩ����ֻ����ȫ��Ѫ�����Ѷ��ᣬ�����������á�\n"NOR,find_player(plerb_id));
			    buse="cannot";
			    call_out("buse_free",10+random(11));
			}	
			return 1;
		}

		if(arg=="killc")
		{
			if(a_power<5) return notify_fail("��������������ʽ��\n");
			if(ause!="ok")  return notify_fail("��Ѩ�����⣬�޷�ʩչ������\n");
			if(a_sword<=0) return notify_fail("���������޽�����γ��У�\n");

                        a_power-=(3+random(3));
                        a_busy+=(1+random(2));
			if(b_sword>=1)
			{
			    message_vision(HIY"\n$N����һ������������������һʽ���ƽ�˪����������Է����г�����\n"NOR,me);
			    switch(random(3))
			    {
				case 0:
				message("vision",WHT"ֻ��"+plerb_name+"�������ң�����ܹ���\n",this_object(),find_player(plerb_id));
				tell_object(find_player(plerb_id),WHT"����Цһ��������ܹ���\n"NOR);
				break;

				case 1:
				message_vision(HIC"$Nӭ�������࿹�����ϡ���һ�����������г���ͬʱ����\n"NOR,find_player(plerb_id));
				a_sword-=(10+random(11));
				b_sword-=(15+random(16));
				check_sword();
				break;

				case 2:
				message_vision(HIB"ֻ���á��ϡ���һ����$N���г����ѱ�����һ�����ӣ�\n"NOR,find_player(plerb_id));
				b_sword-=(30+random(21));
				check_sword();
				break;
			    }
			}

			else
			{
			    message_vision(HIY"\n$N����һ������Ȼ�ԶԷ��ֱ�������ʩչ�����ƽ�˪����������ȥ��\n"NOR,me);
			    switch(random(3))
			    {
				case 0:
				message("vision",WHT"ֻ��"+plerb_name+"�������ң�����ܹ���\n",this_object(),find_player(plerb_id));
				tell_object(find_player(plerb_id),WHT"����Цһ��������ܹ���\n"NOR);
				break;
				default:
				message_vision(HIR"$N�޷��࿹��ֻ���á����ۡ�������������Ȼ���У���ʱ��Ѫ�Ľ���\n"NOR,find_player(plerb_id));
				b_hp-=(10+random(11));
				check_hp();
			    }
			}
			return 1;
		}

		write(plera_name+"����Ҫ��ʲô��ʽ��\n");
		return 1;
	}

// ��������������������������������
// �������� �ڶ���ҵĳ��� ��������
// ��������������������������������


	if(me->query("id") == plerb_id)
	{
		if(!arg) return notify_fail("��ʽ��kk <k / up / heal / killa / killb / killc> \n");
		if(b_busy>0)
		{
			tell_object(me,"�����һ��������û����ɣ�Խ��ֻ��Խ�ң�\n");
			b_busy+=(random(2));
			return 1;
		}

		if(b_power<=0 && arg!="up") return notify_fail("�����������κ���ʽ��\n");

		if(arg=="k")
		{
			if(b_power<2) return notify_fail("��������������\n");
			b_power--;
			b_busy+=(1+random(2));
			b_gjl=(5+random(6));
			attacker="bbb";
			atk_k();
			return 1;
		
}

		if(arg=="up")
		{
			if(b_power>=25) return notify_fail("�������������\n");
			if(buse!="ok") return notify_fail("��Ѩ�����⣬�޷�����������\n");
			message_vision(HIC"$N���һ����˫��ͻȻ����һ����ȫ����������ɱ��ɢ�������\n"NOR,me);
			b_power+=(3+random(3));
			b_busy+=(2+random(4));
			return 1;
		}

		if(arg=="heal")
		{
			if(b_hp>=80) return notify_fail("�����ڻ������úܣ�\n");
			if(b_power<10) return notify_fail("����������㣬�޷��ָ���Ϣ��\n");
			message_vision(HIG"$N���������һ���������������ö��ˡ�\n"NOR,me);
			b_hp+=(10+random(11));
			b_power-=(5+random(6));
			b_busy+=(1+random(2));
			return 1;
		}

		if(arg=="killa")
		{
			if(b_power<15) return notify_fail("����������������ʽ��\n");
			if(buse!="ok") return notify_fail("��Ѩ�����⣬�޷�ʩչ������\n");
			message_vision(HIC"\n$N��Хһ��������Ծ�����Ǿ�����̤�������ȡ���\n",me);
			b_busy+=(3+random(3));
			atk_timesb=(((b_power-15)/3)+5);
			b_power=0;
			atkb_killa();
			return 1;
		}

		if(arg=="killb")
		{
			if(buse=="ok" && b_power<10) return notify_fail("����������������ʽ��\n");
			if(buse!="ok")
			{
				if(b_power<5) return notify_fail("����������������ʽ��\n");
				b_power-=5;
                                b_busy+=1;
				switch(random(4))
				{
				    case 0:message_vision(HIG"$N����ֱ�屻��Ѩ������Ȼֻ����Ѫ�泩��Ѩ���忪�ˣ�\n"NOR,me);
				    buse="ok";
				    break;
				    default:message_vision(HIY"$N����ֱ�屻��Ѩ����ȴ�޷��⿪���շ�һ��������\n"NOR,me);
				}
				return 1;
			}
			if(ause!="ok") return notify_fail("�Է���Ѩ����û���ء�\n");

			b_power-=10;
			b_busy+=2;
			message("vision",HIB"\n������ǰһ����ֻ��"+plerb_name+"ͻȻ���ƹ��ȣ�����ƽ�"+plera_name+"��ʩչ���ˡ���Ӱ��Ѩ�֡���\n"NOR,this_object(),({me,find_player(plera_id)}));
			tell_object(me,HIB"\n��˲��ƽ�"+plera_name+"����Ȼʩչ���ˡ���Ӱ��Ѩ�֡���\n"NOR);
			tell_object(find_player(plera_id),HIB"\n����ǰһ����ֻ��"+plerb_name+"�Ƶ������ǰ����Ȼʩչ���ˡ���Ӱ��Ѩ�֡���\n"NOR);

			switch(random(3))
			{
			    case 0:message_vision(WHT"$N��֮�¼�æ�������������о����գ�\n"NOR,find_player(plera_id));
			    break;
			    default:message_vision(HIR"$Nһ���ӱ�����Ѩ����ֻ����ȫ��Ѫ�����Ѷ��ᣬ�����������á�\n"NOR,find_player(plera_id));
			    ause="cannot";
			    call_out("ause_free",10+random(11));
			}	
			return 1;
		}

		if(arg=="killc")
		{
			if(b_power<5) return notify_fail("��������������ʽ��\n");
			if(buse!="ok")  return notify_fail("��Ѩ�����⣬�޷�ʩչ������\n");
			if(b_sword<=0) return notify_fail("���������޽�����γ��У�\n");

                        b_power-=(3+random(3));
                        b_busy+=(1+random(2));
			if(a_sword>=1)
			{
			    message_vision(HIY"\n$N����һ������������������һʽ���ƽ�˪����������Է����г�����\n"NOR,me);
			    switch(random(3))
			    {
				case 0:
				message("vision",WHT"ֻ��"+plera_name+"�������ң�����ܹ���\n",this_object(),find_player(plera_id));
				tell_object(find_player(plera_id),WHT"����Цһ��������ܹ���\n"NOR);
				break;

				case 1:
				message_vision(HIC"$Nӭ�������࿹�����ϡ���һ�����������г���ͬʱ����\n"NOR,find_player(plera_id));
				b_sword-=(10+random(11));
				a_sword-=(15+random(16));
				check_sword();
				break;

				case 2:
				message_vision(HIB"ֻ���á��ϡ���һ����$N���г����ѱ�����һ�����ӣ�\n"NOR,find_player(plera_id));
				a_sword-=(30+random(21));
				check_sword();
				break;
			    }
			}

			else
			{
			    message_vision(HIY"\n$N����һ������Ȼ�ԶԷ��ֱ�������ʩչ�����ƽ�˪����������ȥ��\n"NOR,me);
			    switch(random(3))
			    {
				case 0:
				message("vision",WHT"ֻ��"+plera_name+"�������ң�����ܹ���\n",this_object(),find_player(plera_id));
				tell_object(find_player(plera_id),WHT"����Цһ��������ܹ���\n"NOR);
				break;
				default:
				message_vision(HIR"$N�޷��࿹��ֻ���á����ۡ�������������Ȼ���У���ʱ��Ѫ�Ľ���\n"NOR,find_player(plera_id));
				a_hp-=(10+random(11));
				check_hp();
			    }
			}
			return 1;
		}
		write(plerb_name+"����Ҫ��ʲô��ʽ��\n");
		return 1;
	}

	message_vision(CYN"$N���ŵش����к��š����ͣ����ͣ��������Ǻ޲���Ҫ����̨ȥ��æ�Ƶġ�\n"NOR,me);
	return 1;
}

// ����������������������������������
// �������� ����ҵĳ��湥�� ��������
// ����������������������������������

void atk_k()
{
	object temp_a,temp_b,ob;
	string temp_namea,temp_nameb;
	int temp_hp,temp_sword,temp_gjl;

	ob=this_object();

	if(attacker=="aaa")
	{
		temp_a=find_player(plera_id);
		temp_b=find_player(plerb_id);
		temp_namea=plera_name;
		temp_nameb=plerb_name;
		temp_sword=a_sword;
		temp_hp=b_hp;
		temp_gjl=a_gjl;
	}

	else
	{
		temp_a=find_player(plerb_id);
		temp_b=find_player(plera_id);
		temp_namea=plerb_name;
		temp_nameb=plera_name;
		temp_sword=b_sword;
		temp_hp=a_hp;
		temp_gjl=b_gjl;
	}

	if(!temp_a || !temp_b) return;

	if(temp_sword<=0)
	{
		switch(random(2))
		{
		    case 0:
		    message("vision",CYN"ֻ��"+temp_namea+"��Ȼ����ƽ�"+temp_nameb+"��һ���������·������伱����ȥ��\n"NOR,ob,({temp_a,temp_b}));
		    tell_object(temp_a,"������ƽ�"+temp_nameb+"��һ���������·������伱����ȥ��\n");
		    tell_object(temp_b,temp_namea+"��Ȼ����ƽ��㣬һ��
�������·������㼱��������\n");
		    break;

		    case 1:
		    message("vision",CYN"ֻ��"+temp_namea+"���ֻ���������ȭ�����رƽ�"+temp_nameb+"�����䵱�ػ���һȭ��\n"NOR,ob,({temp_a,temp_b}));
		    tell_object(temp_a,"������ƽ�"+temp_nameb+"��������ȭ���䵱�ػ�ȥ��\n");
		    tell_object(temp_b,temp_namea+"��Ȼ����ƽ��㣬������ȭ���㼱��������\n");
		    break;
		}
	}

	else
	{
		temp_gjl+=((temp_sword/10)+1);

		switch(random(3))
		{
		    case 0:
		    message("vision",CYN"ֻ��"+temp_namea+"�����׷ɣ���ʱ���ѽ�"+temp_nameb+"�����ڽ�Ӱ֮�£�\n"NOR,ob,({temp_a,temp_b}));
		    tell_object(temp_a,"�����𽣻������ָ��"+temp_nameb+"�������Ѩ��\n");
		    tell_object(temp_b,temp_namea+"���𽣻���ɲ�Ǽ佣���������������Ѩ��\n");
		    break;

		    case 1:
		    message("vision",CYN"ֻ��"+temp_namea+"����һ���̳�����һ������ƽ����"+temp_nameb+"ȴ��Ȼ�޷������κ�������\n"NOR,ob,({temp_a,temp_b}));
		    tell_object(temp_a,"��ͦ������"+temp_nameb+"���̶�����\n");
		    tell_object(temp_b,temp_namea+"����ͦ�����㼲�̶�����\n");
		    break;

		    case 2:
		    message("vision",CYN"ֻ��"+temp_namea+"���б�ã���������"+temp_nameb+"�ὣ��ȥ��\n"NOR,ob,({temp_a,temp_b}));
		    tell_object(temp_a,"���ս�����������"+temp_nameb+"������ȥ��\n");
		    tell_object(temp_b,temp_namea+"���ر����ս���һ����Ӱ������Ữ������\n");
		    break;
		}
	}

	switch(random(3))
	{
		case 0:
		message("vision",""WHT""+temp_nameb+"��Ȼһ�Σ���֪��ô�ľ��Ѷ����"+temp_namea+"�Ĺ�����\n"NOR,ob,({temp_a,temp_b}));
		tell_object(temp_a,WHT"ֻ��"+temp_nameb+"��Ȼһ�Σ���֪��ô�ľ��Ѷ������Ĺ�����\n"NOR);
		tell_object(temp_b,WHT"����Ȼһ�Σ����ɵ�������"+temp_namea+"�Ĺ�����\n"NOR);
		break;

		case 1:
		message("vision",""YEL""+temp_nameb+"��֮�¾�����񣬵���������һ������"+temp_namea+"�������У�\n"NOR,ob,({temp_a,temp_b}));
		tell_object(temp_a,YEL"ֻ��"+temp_nameb+"��Ȼ�������������Ա������ˡ�\n"NOR);
		tell_object(temp_b,YEL"����Ȼ��������������������һ�����������˵��ˡ�\n"NOR);
		temp_hp-=(temp_gjl/2);
		break;

		case 2:
		message("vision",""HIR""+temp_nameb+"���޿ɵ������޿ɱܣ�Ψ��Ӧ�����У�\n"NOR,ob,({temp_a,temp_b}));
		tell_object(temp_a,HIR"ֻ��"+temp_nameb+"���޿ɵ������޿ɱܣ�Ӧ�����У�\n"NOR);
		tell_object(temp_b,HIR"�㲻���赲�����һ������Ȼ���У�\n"NOR);
		temp_hp-=(temp_gjl);
		break;
	}

	if(attacker=="aaa") b_hp=temp_hp;
	else a_hp=temp_hp;

	check_hp();
}

void atka_killa()
{
	object ob,me,whoa;

	ob=this_object();
	me=this_player();
	whoa=find_player(plerb_id);

	message("vision",""HIY""+plera_name+"���ڰ�գ�����ȴ�������������"+plerb_name+"��ȥ��\n"NOR,this_object(),({me,whoa}));
	tell_object(whoa,""HIY""+plera_name+"���ڰ�գ�����ȴ�������������������������\n"NOR);
	tell_object(me,HIY"�����ڰ�գ�����ȴ�������������"+plerb_name+"��ȥ��\n"NOR);

	switch(random(3))
	{
		case 0:b_hp-=(10+random(5));
		message_vision(HIR"$N�������ã���������һ�ţ�\n"NOR,whoa);
		break;
		case 1:b_hp-=(5+random(6));
		message_vision(YEL"$N��ǿжȥһЩ�����������Ǳ��߸����ţ�\n"NOR,whoa);
		break;
		case 2:message_vision(WHT"$N�������ˣ������������һ�ţ�\n"NOR,whoa);
		break;
	}

	atk_timesa--;
	if(atk_timesa<=0)
	{
		message("vision",""HIC""+plera_name+"�������꣬ƮȻ�µء�\n\n"NOR,this_object(),me);
		tell_object(me,HIC"��������꣬ƮȻ�µء�\n\n"NOR);
		check_hp();
		return;
	}
	else atka_killa();
}


void atkb_killa()
{
	object ob,me,whob;

	ob=this_object();
	me=this_player();
	whob=find_player(plera_id);

	message("vision",""HIY""+plerb_name+"���ڰ�գ�����ȴ�������������"+plera_name+"��ȥ��\n"NOR,this_object(),({me,whob}));
	tell_object(whob,""HIY""+plerb_name+"���ڰ�գ�����ȴ�������������������������\n"NOR);
	tell_object(me,HIY"�����ڰ�գ�����ȴ�������������"+plera_name+"��ȥ��\n"NOR);

	switch(random(3))
	{
		case 0:a_hp-=(10+random(5));
		message_vision(HIR"$N�������ã���������һ�ţ�\n"NOR,whob);
		break;
		case 1:a_hp-=(5+random(6));
		message_vision(YEL"$N��ǿжȥһЩ�����������Ǳ��߸����ţ�\n"NOR,whob);
		break;
		case 2:message_vision(WHT"$N�������ˣ������������һ�ţ�\n"NOR,whob);
		break;
	}

	atk_timesb--;
	if(atk_timesb<=0)
	{
		message("vision",""HIC""+plerb_name+"�������꣬ƮȻ�µء�\n\n"NOR,this_object(),me);
		tell_object(me,HIC"��������꣬ƮȻ�µء�\n\n"NOR);
		check_hp();
		return;
	}
	else atkb_killa();
}

void ause_free()
{
	if(games!="fighting" && games!="wait_start") return;
	if(ause=="ok") return;
	ause="ok";
	message_vision(HIG"$N���������泩��Ѩ�����ڽ⿪�ˡ�\n"NOR,find_player(plera_id));
}

void buse_free()
{
	if(games!="fighting" && games!="wait_start") return;
	if(buse=="ok") return;
	buse="ok";
	message_vision(HIG"$N���������泩��Ѩ�����ڽ⿪�ˡ�\n"NOR,find_player(plerb_id));
}

void check_sword()
{
	if(games!="fighting" && games!="wait_start") return;
	if(a_sword<=0)
		message_vision("\n$N�������г����ѳɷ��ֻ���׵�һ�ԣ�������ս��\n\n",find_player(plera_id));
	if(b_sword<=0)
		message_vision("\n$N�������г����ѳɷ��ֻ���׵�һ�ԣ�������ս��\n\n",find_player(plerb_id));
}

int valid_leave(object me, string dir)
{
	if(this_player()->query_temp("duchang/fighting"))
		return notify_fail("�㻹������Ϸ�أ���ô�ܵ��ɲ��ðɡ�\n");
        return ::valid_leave(me, dir);
}
