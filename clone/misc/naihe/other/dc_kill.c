//                ��׼��������ʾ��                                   |
// �ĳ���Ϸ����������������ս��֮������Ϸ�� dc_kill.c
// by naihe ��ï��   2002-05-28ʼ����05-29������ɣ�����
// 06-01 �޸���һЩbug.  06-24 �������ʡ�

#include <ansi.h>
inherit ROOM;

void times();
void ck_hp();
void atc_l();
void atc_k();
void atc_kk();
void atc_kill();
void atc_kill_yeah();
void atc_jianyi();
void win_lose();
void ob_atc();
void ob_k();
void ob_t();
void ob_l();
void games_free();
void top_win();
string look_pai();

int nowtime,mehp,obhp,me_busy,obtime,t_play,t_jj,t_jjs,
me_power,ob_busy,me_gjl,temp,top_high,top_times,level;

string mename,obname,games,time_goon,temp_id,temp_kill,top_name,auto_hp,
games="free";

void create()
{
	set("short", HIW"������Ϸ����������ս����Ϸ"NOR);
	set("long", "������������Ϸ������ӭ�ſɼ�����λ�ô��Ÿ���̨�����ƺ�����ͨ����̨
������ͬ���������͵���Ϸ����ߵĶĲ���Ϸ��ͬ���ǣ�������Ϸ����Ȥ������
�ڽ��𣬶���Ҫ��������Ϸ�������Ȥ�����������Ϸ����������ս�������ſ�
�Ա���һ�Ŵ���ֽ������"HIW"��˵������shuoming��"NOR"�������֣�ֽ�߻�������һ��
С���ӣ�pai����\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);
	set("no_clean_up",1);
	set("no_refresh",1);  // ��һ��Ӧ��������NPC�ϵġ�����д�˲�֪����������xixi
	set("item_desc",([
	    "shuoming":"
"HIG"����������������������������������������������������������������������������"NOR"
                           "HIG"��  Ϸ  ˵  ��"NOR"

"HIY"ÿ����Ϸ��Ҫ1���ƽ�"NOR"������Ϸ����ʱ���� "HIY"start auto"NOR" ��ʾʹ���Զ���ʾ״̬ģʽ��
������Ҫ�Զ���ʾ״̬��ֱ������ start ���ɡ�

����Ϸ������ģ�����ս����˭"HIY"�ڹ涨ʱ���ڰѶԷ���"NOR"��Ϊʤ����

��"HIY"ʱ�䵽��"NOR"�����߶�����ʣ����Ϣ������"HIY"��Ϣ����ΪӮ"NOR"����Ϸָ�����£�

"HIY"kk k"NOR" ---���湥�� "HIY"kk t"NOR" ---ͻϮ "HIY"kk l"NOR" ---���ܾ��˵Ĺ���  "HIY"ck"NOR" ---��ѯ��ǰ״̬

"HIY"kk kill"NOR" ---ʹ�þ�������  "HIY"kk heal"NOR" ---ʹ�þ�������  "HIR"xxx"NOR" ---��ѯ��ǰ��߳ɼ���¼

"HIG"��ע�⣺ʹ�þ�������ʱ����������ֵ�Ĳ�ͬ���Զ�ѡ����ʽ����"NOR"

�����ȡ��ʤ����ʱ�򣬽���"HIY"��ʱ�䡢���˼�ʣ������"NOR"�������"HIY"��ò�ͬ�̶ȵĽ���"NOR"��

"HIG"ע�⣺������ָ���Ҫ��ͬ������ֵ�����һ������ͬ�Ĺ�������
�������Լ���ͬ��busy time�ȡ�ѡ�����������
                                                   --by naihe 02-05-29"NOR"
"HIG"����������������������������������������������������������������������������"NOR"\n",
	    "pai":(: look_pai :),
	]));

	set("exits", ([
	    "east" : __DIR__"dc_dating",
	    "north":__DIR__"dc_huaquan",
	    "west":__DIR__"dc_fight",
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
//	add_action("do_yun","yun");  �����ʱ���Կ��ǲ�Ҫ��
	add_action("do_start","start");
	add_action("do_kk","kk");
	add_action("do_ckhp","ck");
	add_action("do_xxx","xxx");
	if(wizardp(this_player())) add_action("do_powerup","powerup");
}

void reset() 
{ 
              ::reset(); 
              set("no_clean_up", 1); 
} 

string look_pai()
{
	if(wizardp(this_player())) write("��ʦ����Ϸʱ���� powerup <a/b/c>����������ֵ��\n");
	return "ֻ�������ϼ������֣�"HIC"�����˹���������Ʒ"NOR" ��\n";
}

int do_xxx(string arg)
{
	int tempa,tempb;

	if(arg=="hp")
	{
		write(mename+"��Ϣ��"HIR""+mehp+""NOR"/100��������"HIY""+me_power+""NOR"/30������æʱ��"HIC""+me_busy+""NOR"����Ϸ������Ϣ��"HIR""+obhp+" "NOR"��ʣ��ʱ�䣺"+nowtime+" ��\n");
		return 1;
	}

	write("\n ��ǰ��߼�¼����"HIG"��"+top_times+"������"NOR+HIY""+top_name+""NOR"�����"HIY""+top_high+""NOR"��ĳɼ���\n");

	if(!wizardp(this_player())) return 1;
	if(t_jjs>99)
	{
		tempa=(t_jjs/100);
		tempb=(t_jjs-tempa*100);
		t_jjs=tempb;
		t_jj+=tempa;
	}
	write("����Ϸ������"HIG""+t_play+""NOR" ���������"HIG""+t_jj+""NOR" �� "HIG""+t_jjs+""NOR" �� .\n");
	return 1;
}

int do_powerup(string arg)
{
	if(games!="busy") return notify_fail("���ڲ�������Ϸ�С�\n");
	if(this_player()->query("id") !=temp_id)
		return notify_fail("�ֲ������������ʦ����Ϲ��������\n");

	if(!arg) arg="a";
//		return notify_fail("��˼�ǲ�Ҫ�����ˣ�����\n");

	if(arg!="a" && arg!="b" && arg!="c") return notify_fail("ֻ����powerup a��b��c ��a 16�㣻b 21�㣻c 31�㡣\n");
	if(games!="busy") return notify_fail("��û��ʼ��Ϸ�أ�����up�˳�ȥPKѽ��\n");
	if(me_power>=30) return notify_fail("�㻹��up��ʲô�ز�������\n");
	message("vision",HIM"��Ȼֻ����һ����У���������ʦ��̫���Ͼ���������������ֻ��"+mename+"���ѻ��������־��\n"NOR,this_object());
	if(arg=="a") me_power=16;
	if(arg=="b") me_power=21;
	if(arg=="c") me_power=31;
	me_busy=0;
	return 1;
}

int do_yun()
{
	write("����������Ϸ�ģ���զ�Ļ������\n");
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

void times()
{
	if(time_goon!="yes") return;
	if(nowtime==60)
	{
		mehp=100;
		obhp=100;
		games="busy";
		me_busy=0;
		me_power=(5+random(11));
		ob_busy=2;
		obtime=0;
		message("vision",HIR"������ʼ������\n"NOR,this_object());
	}

	if(nowtime<=0)
	{
		message("vision",""HIM"ʱ�䵽��������������������"NOR"\n",this_object());
		win_lose();
		return;
	}

	me_busy--;
	if(me_busy<=0) me_busy=0;
	obtime++;
	if(mehp<=98)
	{
		if(level!=2) mehp+=(random(3));
		else mehp+=(random(2));
	}
	if(obhp<=98) obhp+=(random(2));

	if(me_power<=30 && temp_kill=="free")
	{
		if(level!=2) me_power+=(random(level));
		else if(random(4)!=0) me_power++;
	}

	if(me_power>=30)
	{
		if(random(3)==1) message("vision",HIC"ֻ��"+mename+"˫Ŀһ�����������й�â������\n"NOR,this_object());
	}

	nowtime--;
	write(HIG"\n                              �� "+nowtime+" ��\n"NOR"");

	if(obtime>ob_busy)
	{
		if(random(level)==1) ob_atc();
	}

	if(auto_hp=="yes")
		write(mename+"��Ϣ��"HIR""+mehp+""NOR"/100��������"HIY""+me_power+""NOR"/30������æʱ��"HIC""+me_busy+""NOR"����Ϸ������Ϣ��"HIR""+obhp+" "NOR"��ʣ��ʱ�䣺"+nowtime+" ��\n");

	call_out("times",1);
}

void ob_atc()
{
	if(obhp<30 && random(5)==3)
	{
	    message("vision",""HIG""+obname+"���������һ����������������ö��ˡ�\n"NOR,this_object());
	    ob_busy=(5+random(3));
	    obhp+=(10+random(11));
	    obtime=0;
	    return;
	}

	switch(random(6))
	{
	    case 0:ob_l();
	    break;
	    case 1:ob_t();
	    break;
	    case 2:ob_t();
	    break;
	    default:ob_k();
	}

	obtime=0;
	ck_hp();
	ob_busy=(random(2)+random(level));
}

void ob_k()
{
	message("vision",CYN"ֻ��"+obname+"ƽ���������"+mename+"������һ�У�\n"NOR,this_object());
	switch(random(2))
	{
	    case 0:mehp-=(10+random(11)+((5-level)*3));
	    message("vision",""HIR""+mename+"�������ã�����������һ�ƣ�\n"NOR,this_object());
	    if(me_power<=29 && temp_kill=="free") me_power+=(1+random(3));
	    break;
	    case 1:
	    message("vision",""WHT""+mename+"�������֮�£����ù����⿴��ƽ��ʵ�����յ�һ�У�\n"NOR,this_object());
	    break;
	}
}

void ob_t()
{
	message("vision",""CYN""+obname+"��Ȼ������䣬���ƹ��Ȱ�����"+mename+"��ȥ��\n"NOR,this_object());
	switch(random(3))
	{
	    case 0:mehp-=(10+random(21)+((5-level)*3));
	    message("vision",""HIR""+mename+"��δ���壬���Ѿ����˵�����\n"NOR,this_object());
	    if(me_power<=29 && temp_kill=="free") me_power+=(1+random(3));
	    break;
	    default:
	    message("vision",""WHT""+mename+"�ۻ�����֮���轣�һӣ���Ȼȫ�������ˣ�\n"NOR,this_object());
	}
}

void ob_l()
{
	message("vision",CYN"��Ȼ��ֻ��"+obname+"���Դ�����������"+mename+"�������У�\n"NOR,this_object());
	switch(random(4))
	{
	    case 0:mehp-=(10+random(31)+((5-level)*3));
	    message("vision",""HIR""+mename+"һʱ�䲻֪�Ӻεֵ���Ψ��ƴ��ȫ�����£�\n"NOR,this_object());
	    if(me_power<=29 && temp_kill=="free") me_power+=(2+random(3));
	    break;
	    default:
	    message("vision",""WHT""+mename+"�鼱֮�о͵ش��˼��������Ǳ�ȴ�ǳ���Ч�ض���˹�����\n"NOR,this_object());
	}
}

int do_start(string arg)
{
	object me,qian;
	string tempa,tempb;
	int tempc;

	me=this_player();
	qian=present("gold_money",me);

	if(games!="free") return notify_fail("����������Ϸ����ȴ���Ϸ���������ԡ�\n");
	if(!qian) return notify_fail("����Ϸֻ���ܻƽ�������Я��1�����Ͻ������ԡ�\n");

	if(!arg || arg!="auto")
	{
		auto_hp="no";
		write(HIG"����ѡ���ֶ���ѯ״̬��ʽ��ÿ�β�ѯ�ļ��Ϊ3�룬��ע�⡣\n"NOR);
	}

	else
	{
		auto_hp="yes";
		write(HIG"����ѡ���Զ���ʾ״̬��ʽ�����״̬����ÿ����ʾһ�Ρ���Ϸ���𽫼���Ϊԭ����9/10��\n"NOR);
	}

	qian->add_amount(-1);
	t_play++;
	games="baoming";

	mename=me->query("name");

	switch(random(10))
	{
		case 0:tempa="��";
		break;
		case 1:tempa="��";
		break;
		case 2:tempa="��";
		break;
		case 3:tempa="��";
		break;
		case 4:tempa="��";
		break;
		case 5:tempa="��";
		break;
		case 6:tempa="��";
		break;
		case 7:tempa="���";
		break;
		case 8:tempa="��";
		break;
		case 9:tempa="�Ϲ�";
		break;
	}

	switch(random(10))
	{
		case 0:tempb="��";
		break;
		case 1:tempb="��";
		break;
		case 2:tempb="��";
		break;
		case 3:tempb="ɷ";
		break;
		case 4:tempb="��";
		break;
		case 5:tempb="��";
		break;
		case 6:tempb="��";
		break;
		case 7:tempb="ӭ";
		break;
		case 8:tempb="ɭ";
		break;
		case 9:tempb="Ȼ";
		break;
	}

	temp_id=this_player()->query("id");
	obname=tempa+tempb;
	message_vision(GRN"$N�ó�һ���ƽ������������Ϸ��ʼ�ˣ�����\n"NOR,this_player());
	message("vision",HIM"ֻ��̨�Ϻ�Ȼ�ֳ�������Ӱ������֮һ�������ľ���"+mename+"��ģ����\n"NOR,this_object());
	write(""HIC"��ʹ��ָ�� kk ����ָ�Ӳ�����"NOR"\n");
	message("vision",HIW"��������������ʼ�����������"NOR+HIY""+mename+""NOR+HIW"����Ϸ���"NOR+HIY""+obname+""NOR+HIW"������"NOR"\n",this_object());
	call_out("times",3);
	time_goon="yes";
	temp_kill="free";
	temp=0;

// ÿ��������ʱ���趨����λΪ�롣����ʱ��Ҫ��Ӧ����void times() ���ж�Ӧ��ֵ��
	nowtime=60;

// �Ѷ����á�
	tempc=(t_play-t_jj);
	if(tempc>=10) level=(3+random(4));
	if(tempc<10 && tempc>-10) level=3;
	if(tempc<=-10) level=2;

//	level=2;  ����ǲ����õģ����Ѷ�Ϊ����ʱ������Ӧ���� 60%-80%���ҡ�

	if(wizardp(this_player())) write("�����Ѷ��ǣ�ԽСԽ�ѣ���"+level+".\n");
	return 1;
}

int do_kk(string arg)
{
	object ob=this_object();
	int me_mz;

	if(games!="busy") return notify_fail("���ڲ�������Ϸ�С�\n");
	if(this_player()->query("id") !=temp_id)
	{
		message_vision(CYN"$N������������"+mename+"�����ͣ�"+mename+"�����ͣ�������������Ϸ�е�"+mename+"��Ҫ���š�\n"NOR,this_player());
		return 1;
	}

	if(!arg) return notify_fail("����ָ�kk k / kk t / kk l / kk kill / kk heal.\n");
	if(temp_kill!="free") return notify_fail("������ʩչ"+temp_kill+"����δ������\n");
	if(me_busy>0)
	{
		if(wizardp(this_player())) write("������ƻ�û�ָ������أ�Խ��ֻ��Խ��æ���ң�æʱ�ǣ�"+me_busy+"�롣\n");
		else write("������ƻ�û�ָ������أ�Խ��ֻ��Խ��æ���ң�\n");
		me_busy+=(random(2));
		return 1;
	}

	if(arg!="k" && arg!="t" && arg!="l" && arg!="kill" && arg!="heal")
		return notify_fail("��Ҫ��ʲô��ʽȥ������\n");

	if(arg=="k")
	{
		if(me_power<2) return notify_fail("��������������ʽ��������ЪЪ�ɣ�\n");
		me_busy=(1+random(3));
// ������������æʱ
		me_gjl=(5+random(11)+(level-2));
// ������
		me_mz=3;
// ������
		me_power-=(1+random(2));
// ����ֵ����

		switch(random(8))
		{
		    case 0:message("vision",GRN"ֻ��"+mename+"�������ƣ�ֱ��"+obname+"�����ȥ��\n"NOR,ob);
		    break;
		    case 1:message("vision",GRN"ֻ��"+mename+"���������һ�£������ս���"+obname+"��ͷ�����˹�ȥ��\n"NOR,ob);
		    break;
		    case 2:message("vision",GRN"ֻ��"+mename+"ͦ��б�̣�ֱ��"+obname+"�Ҳ๥ȥ��\n"NOR,ob);
		    break;
		    case 3:message("vision",GRN"ֻ��"+mename+"������������һ�£�ԭ��ȴ�ǹ���"+obname+"�����ȣ�\n"NOR,ob);
		    break;
		    case 4:message("vision",GRN"ֻ��"+mename+"������������һ�£�ԭ��ȴ�ǹ���"+obname+"�����ȣ�\n"NOR,ob);
		    break;
		    case 5:message("vision",GRN"ֻ��"+mename+"�粽���ƣ���"+obname+"��δ����֮ʱ����Ϊȭ������"+obname+"��ͷ����\n"NOR,ob);
		    break;
		    case 6:message("vision",GRN"ֻ��"+mename+"�������̼��£��ֱ���"+obname+"����������·��\n"NOR,ob);
		    break;
		    case 7:message("vision",GRN"ֻ��"+mename+"�������Ʋ�����ȴԭ�������У���ʵ��������"+obname+"�������ĳ���һ�ƣ�\n"NOR,ob);
		    break;
		}
	}

	if(arg=="t")
	{
		if(me_power<3) return notify_fail("��������������ʽ��������ЪЪ�ɣ�\n");
		me_busy=(2+random(3));
		me_gjl=(15+random(11)+(level-2));
		me_mz=4;
		me_power-=3;

		switch(random(5))
		{
		    case 0:message("vision",HIB"����ֻ��"+mename+"����Ծ���԰������"+obname+"Ϯȥ���˵�������ޱȣ�\n"NOR,ob);
		    break;
		    case 1:message("vision",HIB"����ֻ��"+mename+"�Ჽ��ǰ�����ֽ����һ��һ��ͬʱ��"+obname+"��ȥ��\n"NOR,ob);
		    break;
		    case 2:message("vision",HIB"ֻ��"+mename+"���ذ�����£�������"+obname+"���̼�ɨ��ȥ��\n"NOR,ob);
		    break;
		    case 3:message("vision",HIB"��Ȼ֮��"+mename+"����һ����ȴת����"+obname+"�ı��󰴳���һ�ƣ�\n"NOR,ob);
		    break;
		    case 4:message("vision",HIB"����ֻ��"+mename+"�ӽ���磬ɲ�Ǽ�"+obname+"ȫ�����ڽ�������֮�£�\n"NOR,ob);
		    break;
		}
	}

	if(arg=="l")
	{
		if(me_power<5) return notify_fail("��������������ʽ��������ЪЪ�ɣ�\n");
		me_busy=(3+random(3));
		me_gjl=(15+random(16)+(level-2));
		me_mz=3;
		me_power-=5;

		switch(random(3))
		{
		    case 0:message("vision",RED"����ֻ����"+mename+"���һ��������һ�е�ͦ��ֱ��"+obname+"��ȴ��ƴ���Ĵ򷨣�\n"NOR,ob);
		    break;
		    case 1:message("vision",""RED""+mename+"��Ȼ֮�佣�д��ң�����"+obname+"�����ҿ������ж���ƴ����\n"NOR,ob);
		    break;
		    case 2:message("vision",RED"ֻ��"+mename+"����ֻ��һ��������ȴ��ȫ��������ȫ��ʹ����ȫ��ͬ���ھ�����ʽ��\n"NOR,ob);
		    break;
		}
	}

	if(arg=="kill")
	{
		if(me_power<15) return notify_fail("���������û��ء�\n");
		atc_kill();
	}

	if(arg=="heal")
	{
		if(me_power<8) return notify_fail("���������û��ء�\n");
		if(mehp>90) return notify_fail("������״̬��ͦ���\n");
		message("vision",""HIG""+mename+"���������һ����������������ö��ˡ�\n"NOR,ob);
		me_power-=8;
		me_busy=(1+random(3));
		mehp+=(15+random(6));
	}

	if(arg=="k" || arg=="t" || arg=="l")
	{
		switch(random(me_mz))
		{
			case 0:
			if(arg=="l") atc_l();
			if(arg=="k" || arg=="t") atc_k();
			break;

			case 1:
			if(arg=="l") atc_l();
			if(arg=="k") atc_kk();
			if(arg=="t") atc_k();
			break;

			default:
			switch(random(8))
			{
			    case 0:
			    message("vision",""WHT""+obname+"һ��֮�¼������㣬�����ܹ���\n"NOR,ob);
			    break;
			    case 1:
			    message("vision",""WHT""+obname+"��Ӧ��죬����ܹ���\n"NOR,ob);
			    break;
			    case 2:
			    message("vision",WHT"ֻ��"+obname+"��Ӱһ������Ȼ�����"+mename+"�Ĺ�����\n"NOR,ob);
			    break;
			    case 3:
			    message("vision",WHT"ֻ��"+obname+"����һЦ�����赭д�����˿�ȥ��\n"NOR,ob);
			    break;
			    case 4:
			    message("vision",""WHT""+obname+"�ƺ�δ��������ȴ��֪���ľͻ�����"+mename+"�Ĺ��ơ�\n"NOR,ob);
			    break;
			    case 5:
			    message("vision",""WHT""+obname+"����е��������úã�����ȴһ���Ӱѹ����Լ�����ʽ������ˡ�\n"NOR,ob);
			    break;
			    case 6:
			    message("vision",""WHT""+obname+"�����൲��������ס�����ơ�\n"NOR,ob);
			    break;
			    case 7:
			    message("vision",""WHT""+obname+"��Цһ�������־͸���"+mename+"�Ľ�����\n"NOR,ob);
			    break;
			}
		}
	}
	ck_hp();
	return 1;
}

void ck_hp()
{
	object ob=this_object();

// ������ã���ʹϵͳ����ÿ�غ϶���״̬������Ļ���ҡ�
	if(random(3)==1)
	{
	if(mehp>=100) message("vision",HIW"��"+mename+"�������������ˡ���\n"NOR,ob);
	if(mehp>90 && mehp<100) message("vision",HIW"��"+mename+"�ƺ����˵����ˣ����������¡���\n"NOR,ob);
	if(mehp>70 && mehp<91) message("vision",HIW"��"+mename+"���˵��ˣ���ʼ�����е�����ˡ���\n"NOR,ob);
	if(mehp>50 && mehp<71) message("vision",HIW"��"+mename+"�˵�������ģ���Ե��е��Ǳ�����\n"NOR,ob);
	if(mehp>20 && mehp<51) message("vision",HIW"��"+mename+"�������أ��Ѿ���Ҫ֧�ֲ�ס�ˡ���\n"NOR,ob);
	if(mehp>10 && mehp<21) message("vision",HIW"��"+mename+"�Ѿ�ͷ���ۻ��Ŀ�Ҫ�����ˡ���\n"NOR,ob);
	if(mehp>0 && mehp<11) message("vision",HIW"��"+mename+"ֻʣ���һ���������ڿ��֧���š���\n"NOR,ob);

	if(obhp>=100) message("vision",HIW"��"+obname+"�������������ˡ���\n"NOR,ob);
	if(obhp>90 && obhp<100) message("vision",HIW"��"+obname+"�ƺ����˵����ˣ����������¡���\n"NOR,ob);
	if(obhp>70 && obhp<91) message("vision",HIW"��"+obname+"���˵��ˣ���ʼ�����е�����ˡ���\n"NOR,ob);
	if(obhp>50 && obhp<71) message("vision",HIW"��"+obname+"�˵�������ģ���Ե��е��Ǳ�����\n"NOR,ob);
	if(obhp>20 && obhp<51) message("vision",HIW"��"+obname+"�������أ��Ѿ���Ҫ֧�ֲ�ס�ˡ���\n"NOR,ob);
	if(obhp>10 && obhp<21) message("vision",HIW"��"+obname+"�Ѿ�ͷ���ۻ��Ŀ�Ҫ�����ˡ���\n"NOR,ob);
	if(obhp>0 && obhp<11) message("vision",HIW"��"+obname+"ֻʣ���һ���������ڿ��֧���š���\n"NOR,ob);
	}

	message("vision","\n",ob);
	if(mehp<1 || obhp<1) win_lose();
}

int do_ckhp()  // ����ǽ����Ѷ��˵� ״̬��ѯ������
{
	if(games!="busy") return notify_fail("��Ϸû��ʼ�أ���Ҷ�����úܡ�\n");

	if(this_player()->query("id") !=temp_id)
		return notify_fail("�ֲ����������Ϲ���͸�ɶ��\n");

	if(auto_hp=="yes") return notify_fail("���Ѿ�ѡ�����Զ���ʾ״̬�ˡ�\n");
	if(time()-query_temp("cktime")<3) return notify_fail("�϶���״̬�����㻹�˲��˹���������\n");
	write(mename+"��Ϣ��"HIR""+mehp+""NOR"/100��������"HIY""+me_power+""NOR"/30������æʱ��"HIC""+me_busy+""NOR"����Ϸ������Ϣ��"HIR""+obhp+" "NOR"��ʣ��ʱ�䣺"+nowtime+" ��\n");
	set_temp("cktime",time());
	return 1;
}

void atc_k()
{
	object ob=this_object();
	switch(random(5))
	{
		case 0:message("vision",""HIR""+obname+"������������������ţ�\n"NOR,ob);
		break;
		case 1:message("vision",""HIR""+obname+"������ܣ�ȴ���˰벽�������˸�ȫ�У�\n"NOR,ob);
		break;
		case 2:message("vision",HIR"ֻ��"+obname+"��δ��Ӧ�������Ѿ�Ӧ�����У�\n"NOR,ob);
		break;
		case 3:message("vision",""HIR""+obname+"��֮��δ�����������ʵʵ�س���һ�У�\n"NOR,ob);
		break;
		case 4:message("vision",""HIR""+obname+"���޿ɱܣ������뵲��ȴ�������ģ���ʱ��������У�\n"NOR,ob);
		break;
	}
	obhp-=me_gjl;
}

void atc_kk()
{
	object ob=this_object();
	switch(random(5))
	{
		case 0:message("vision",""YEL""+obname+"ͻȻ������������֮�����������ˡ�\n"NOR,ob);
		break;
		case 1:message("vision",""YEL""+obname+"��������������������ˡ�\n"NOR,ob);
		break;
		case 2:message("vision",YEL"ֻ��"+obname+"����Ťת���Ӷ�ܣ�ȴ����һ�������С�\n"NOR,ob);
		break;
		case 3:message("vision",YEL"ֻ��"+obname+"���������Ȼ�������У����������˲���\n"NOR,ob);
		break;
		case 4:message("vision",""YEL""+obname+"����������������һ�У��ƺ����˲��ء�\n"NOR,ob);
		break;
	}
	obhp-=(me_gjl/2);
}

void atc_l()
{
	int tempme,tempob;
	object ob=this_object();
	switch(random(3))
	{
		case 0:message("vision",""HIR""+obname+"ֻ���޷�������Ψ�з�����ӭ������\n"NOR,ob);
		break;
		case 1:message("vision",""HIR""+obname+"��"+mename+"���ƣ�ֻ��ȫ��һ����Ӳ����ƴ������\n"NOR,ob);
		break;
		case 2:message("vision",""HIR""+obname+"��֮����Ͼϸ�룬Ψ��Ӧ�У�����\n"NOR,ob);
		break;
	}
	message("vision",HIR"����ͬʱ�ƺ�һ���������ش���\n"NOR,ob);
	tempme=((me_gjl*2/3)+random(me_gjl));
	tempob=((me_gjl*2/3)+random(me_gjl));
	mehp-=tempme;
	obhp-=tempob;
}

void atc_kill()
{
	object ob=this_object();

	if(me_power>=30)
	{
		temp_kill="��������ʮ��ʽ";
		temp=0;
		atc_jianyi();
		return;
	}

	if(me_power>=20)
	{
	    message("vision","\n"HIC"ֻ��"+mename+"˲��ƽ�"+obname+"�����ƽ���������"+obname+"����������"NOR+HIR"��������"NOR+HIC"��\n\n\n"NOR,this_object());
	    me_power-=(15+random(6));
	    me_busy=(5+random(4));
	    me_gjl=(10+level-2);

	    message("vision",""HIY""+mename+"����ֱ��������ֱ��"+obname+"ü��һ�㣡\n"NOR,ob);
	    atc_kill_yeah();
	    message("vision",""HIY""+mename+"һ���������������������ϣ�����"+obname+"������ȥ��\n"NOR,ob);
	    atc_kill_yeah();
	    message("vision",HIY"һ�ƻ�δ���ƣ�"+mename+"����֮���ָ����𣬴�����������"+obname+"����������\n"NOR,ob);
	    atc_kill_yeah();
	    message("vision",""HIY""+mename+"���ֽ���δ�����������ѳ��ƻ���������"+obname+"�ٴ��ĳ���\n"NOR,ob);
	    atc_kill_yeah();
	    message("vision",""HIY""+mename+"������������б�����£�����������ǿ��ɱ�ţ�\n"NOR,ob);
	    atc_kill_yeah();
	    return;
	}

	if(me_power>=15)
	{
	    message("vision","\n"HIC"ֻ����"+mename+"�͵ش��һ�����������ֱƽ�"+obname+"�����Ƽ���"+obname+"�������£�\n\n\n"NOR,ob);
	    me_power-=(10+random(6));
	    me_busy=(4+random(3));
	    me_gjl=(15+random(16)+(level-2));
	    obhp-=(me_gjl/2);  // �������ʹ�����Ǿ��Ի��öԷ��ܵ���˵� ����
	    atc_kill_yeah();
	    message("vision",""HIC""+mename+"�������ơ�ʩչ��ϣ�������ʽ����Ծ�˿�ȥ��\n\n"NOR,ob);
	    return;
	}
}

void atc_jianyi()
{
	object ob=this_object();
	me_gjl=(5+random(6)+(level-2));
//	me_power=0;

	if(games!="busy")
	{
	    if(obhp<1) message("vision",""HIC""+mename+"����������Ц��������ʽ�ؽ���\n"NOR,ob);
	    if(mehp<1 && obhp>0) message("vision",HIC"ֻ��"+mename+"��δʹ�ꡰ��������ʮ��ʽ�����Լ�ȴ�ѱ����ˡ�\n"NOR,ob);
	    if(mehp<1 && obhp<1) message("vision",HIC"ֻ��"+mename+"��"+obname+"˫˫���£�����������ʮ��ʽ����Ȼ��ֹ��\n"NOR,ob);
	    if(mehp>1 && obhp>1) message("vision",HIC"����ʱ���ѵ���"+mename+"Ӳ��������ס�ˡ���������ʮ��ʽ�����ؽ����ض�����\n"NOR,ob);
	    return;
	}

	if(temp==0) message("vision",HIC"\n����ֻ��"+mename+"��Хһ������ת��ã�ɲ�Ǽ��޾������ѽ�"+obname+"����Χ�ƣ�\n\n\n"NOR,ob);

	if(temp==12)
	{
		message("vision",HIC"\n"+mename+"����֮�����ⶸ����ֻ���á��ৡ���������ʹ���ˡ���������ʮ��ʽ��֮��ǿһ�У�\n"NOR,ob);
		obhp-=(me_gjl*(1+random(3))+random(me_gjl+1));
		message("vision",""HIR""+obname+"����Ӱ���֣��������˶������ҽ�һ��֮��ֻ����Ѫ�Ľ�����Ȼ���У�\n"NOR,ob);
		ck_hp();
		temp_kill="free";
		temp=0;
		me_power=0;
		return;
	}

	if(temp>=0)
	{
		message("vision",HIY"ֻ��"+mename+"���н������಻��������޷���ֱ�Ƶ�"+obname+"������������\n"NOR,ob);
		atc_kill_yeah();
		ck_hp();
		temp++;

		me_power=((13-temp)*2);
		call_out("atc_jianyi",1);
	}
}


void atc_kill_yeah()
{
	object ob=this_object();
	switch(random(4))
	{
		case 0:message("vision",""HIR""+obname+"ֻ���������أ���ʱ�������ã�Ӧ�ж��У�\n\n"NOR,ob);
		obhp-=(me_gjl+random(me_gjl+1));
		break;
		case 1:message("vision",""YEL""+obname+"���ж���������жȥ������������������ܴ��ˣ�\n\n"NOR,ob);
		obhp-=((me_gjl+random(me_gjl+1))/2);
		break;
		case 2:message("vision",WHT"ɲ�Ǽ�ֻ��"+obname+"����������֮���ֱ������˼��\n\n"NOR,ob);
		break;
		case 3:message("vision",""YEL""+obname+"���ж���������жȥ������������������ܴ��ˣ�\n\n"NOR,ob);
		obhp-=((me_gjl+random(me_gjl+1))/2);
		break;
	}
}

void games_free()
{
	games="free";
}

void win_lose()
{
	object jj_s,jj_g,ob,me;
	int jj_all,tempa,tempb,temp_time;

	ob=this_object();
	me=this_player();
	jj_s=new("/clone/money/silver");
	jj_g=new("/clone/money/gold");

	if(nowtime>0) message("vision",HIM"���˵����ˣ���������������\n"NOR,ob);
	message("vision",HIM"̨�ϵ���Ӱ�������ʣ���ʧ�����ˡ�\n"NOR,ob);
	time_goon="no";
	games="wait";
	call_out("games_free",5);
	temp_time=nowtime;
	nowtime=0;
	obtime=0;
	temp_id="none";

	if(mehp<1 && obhp<1)
	{
		message("vision",HIW"���ֱ�����"+mename+"��"+obname+"�������������ˣ���Ϊƽ�֡���"+mename+"ȡ�ر���ʱ�����ƽ�\n"NOR,ob);
		jj_g->set_amount(1);
// �������ġ�		message("vision",HIW"ֻ�������������һ���׳���һ��"NOR+HIY"�ƽ�"NOR+HIW"��\n"NOR,ob);
		message("vision",HIW"ֻ�������������һ���׳���һ��"NOR+HIY"�ƽ�"NOR+HIW"��"+mename+"�����̵�����������\n"NOR,ob);
// ��Ϊֱ�Ӹ�Ǯ����Ҽ��������ġ�		jj_g->move(environment(me));
		jj_g->move(me);  // �����ֱ�Ӹ���ҽ���ġ�
		t_jj++;
		message("vision",HIW"ϣ������Ϸ�����������֣�лл�� ���� \n"NOR,ob);
		return;
	}
	
	if(mehp<1 && obhp>0)
	{
		message("vision",HIW"���ֱ��������"+mename+"����Ϸ����"+obname+"����ˣ���ӭ�´�������\n"NOR,ob);
		message("vision",HIW"ϣ������Ϸ�����������֣�лл�� ���� \n"NOR,ob);
		return;
	}

	if(mehp>0 && obhp<1)
	{
//		jj_all=((temp_time*((mehp+me_power)/2))*2/3+100); // ���ǱȽ��ѵ����� :)
		jj_all=((temp_time/2)*((mehp+me_power)/2)+100);
		if(auto_hp=="yes")
		{
			write(HIG"�㱾�ֱ�����ѡ�����Զ�״̬��ʾ���ܽ���Ϊ"+jj_all+"����9/10��\n"NOR);
			jj_all=(jj_all*9/10);
		}

// ���ǱȽ����׵����� :) ȫ��ʱΪ4000�����ӣ� �� 60*((100+30)/2)+100 = 4000 .

		message("vision",HIW"���ֱ��������"+mename+"�����ʤ��������\n"NOR,ob);
		message("vision",HIW"��ʱ"+(60-temp_time)+"�룻ʣ����Ϣ"+mehp+"�㣻ʣ������"+me_power+"�㣬����Ϊ"+jj_all+"������������\n"NOR,ob);
		message("vision",HIW"��"+mename+"��ȡӦ�õĽ���ף���㣡\n"NOR,ob);
// ����������		message("vision",HIW"ֻ�������������һ���׳���һЩ"NOR+HIY"����"NOR+HIW"��\n"NOR,ob);
		message("vision",HIW"ֻ�������������һ���׳���һЩ"NOR+HIY"����"NOR+HIW"��"+mename+"�����̵�����������\n"NOR,ob);

// log �ļ���¼��
	        log_file("duchang/KILL_GAME", sprintf("%s(%s)��%s������ս����Ϸ��� %d ��������\n",
                me->query("name"), getuid(me), ctime(time()), jj_all));


		if(jj_all>top_high)
		{
			top_times++;
			message("vision",HIW"\n��ϲ"+mename+"������"+top_name+"�����"+top_high+" �����Ѽ�¼��"+mename+"���¼�¼�ǣ�"+jj_all+"�㣬��ϲ��ϲ��\n\n"NOR,ob);
			CHANNEL_D->do_channel(me, "rumor", sprintf(HIY"%s��"NOR+HIG""+jj_all+""NOR+HIY"��ĳɼ���������"NOR+HIG""+top_name+""NOR+HIY"���ֵ�"NOR+HIG""+top_high+""NOR+HIY"�����Ѽ�¼��\n"NOR, me->query("name")));
			CHANNEL_D->do_channel(me, "rumor", sprintf(HIY"��ϲ%s��Ϊ�ĳ�����ս����Ϸ�е�"+top_times+"�����ߣ�\n"NOR,me->query("name")));
			me->set_temp("duchang/king",top_times);
			top_high=jj_all;
			top_name=(me->query("name"));
			top_win();
		}

		if(jj_all>99)
		{
			tempa=(jj_all/100);
			tempb=(jj_all-tempa*100);
			jj_s->set_amount(tempb);
			jj_g->set_amount(tempa);
// ��Ϊֱ�Ӹ���ҽ���			jj_g->move(environment(me));
			jj_g->move(me); // ֱ�Ӹ�����
			t_jj+=tempa;
			t_jjs+=tempb;
		}

		else
		{
			jj_s->set_amount(jj_all);
			t_jjs+=jj_all;
		}

// ��Ϊֱ�Ӹ���ҽ���		jj_s->move(environment(me));
		jj_s->move(me); // ֱ�Ӹ�����
		return;
	}

	if(mehp>0 && obhp>0)
	{
		message("vision",HIW"���ֱ���ʱ���ѵ���" + mename + "��" + obname + "��δ������������Ϣ����Ϊʤ��\n"NOR,ob);

		if(mehp<obhp)
		{
		    message("vision",""HIW""+obname+"����Ϣ�ϸߣ���ˣ����ֱ���"+mename+"���ˣ�\n"NOR,ob);
		    message("vision",HIW"ϣ������Ϸ�����������֣�лл�� ���� \n"NOR,ob);
		    return;
		}

		if(mehp==obhp)
		{
		    message("vision",HIW"������Ϣֵͬ������Ϊƽ�֡���ȡ�ر���ʱ�����ƽ�\n"NOR,ob);
		    jj_g->set_amount(1);

// ��������		    message("vision",HIW"ֻ�������������һ���׳���һЩ"NOR+HIY"����"NOR+HIW"��\n"NOR,ob);
		    message("vision",HIW"ֻ�������������һ���׳���һЩ"NOR+HIY"����"NOR+HIW"��"+mename+"�����̵�����������\n"NOR,ob);
// ֱ�Ӹ���ҽ���		    jj_g->move(environment(me));
		    jj_g->move(me); // ֱ�Ӹ�����
		    t_jj+=1;
		    message("vision",HIW"ϣ������Ϸ�����������֣�лл�� ���� \n"NOR,ob);
		    return;
		}

		if(mehp>obhp)
		{
		    jj_all=(mehp+me_power);
		    message("vision",""HIW""+mename+"����Ϣ�ϸߣ�ȡ���˱��ֱ�����ʤ����������Ϊ��ο�� "+jj_all+"�����ӣ�\n"NOR,ob);
		    jj_s->set_amount(jj_all);
		    message("vision",HIW"ֻ�������������һ���׳���һЩ"NOR+HIW"����"NOR+HIW"��\n"NOR,ob);
		    jj_s->move(environment(me));
		    t_jjs+=jj_all;
		    message("vision",HIW"ϣ������Ϸ�����������֣�лл�� ���� \n"NOR,ob);
		    return;
		}

	}

}

void top_win()
{
	object me,win_ob,me_ring;
	me=this_player();
	win_ob=new(__DIR__"obj/ring_king");
	me_ring=present("wangzhe ring",me);

	if(!me_ring)
	{
		win_ob->set("long","����һ�����������ָ�����������һȦ��С���֣���"+(int)me->query_temp("duchang/king")+"������ս��֮��"+me->query("name")+"��\n����Զ��������䣨huiyi��ȡ�ý�ָʱ�����ֳɾ͸С�\n");
		win_ob->set("king_times",top_times);
		win_ob->move(me);
		message_vision(HIW"$N�õ���һö "NOR+HIY"����֮��"NOR+HIW" ��\n"NOR,me);
		return;
	}

	me_ring->set("long","����һ�����������ָ�����������һȦ��С���֣���"+(int)me->query_temp("duchang/king")+"������ս��֮��"+me->query("name")+"��\n����Զ��������䣨huiyi��ȡ�ý�ָʱ�����ֳɾ͸С�\n");
	me_ring->set("king_times",top_times);
	message_vision(HIW"$N���ϵ�"NOR+HIY"����֮��"NOR+HIW"�ƺ�������һ��������\n"NOR,me);
}
