// Code of ShenZhou
//mjxiaosi.c
//Remake And Bug fix at 2000,Nov,18 by Mantian

#include <ansi.h>
inherit NPC;
#define MJ_DATA "/data/mj_data.o"
#define END 286
#define START 0
void check_flower(mapping who);
int to_say_play();
int to_say_rule();
int do_dump(string str,object me);
int do_check_Mj(string datastr,string str);
int do_check_eat(string num1,string num2,string LastDump);
int delete_last_dump(string whoId);
int do_check_win(string str);
int check_hu(string strW);
int set_mjdata(object me,int *winner);
int *get_mjdata(string id);
int get_tc(mapping who);
varargs int do_autodump(string str,object me);
varargs int do_touch(string str,object me);
varargs int wash_mj(int amount);
varargs int do_win(string str,object me);
varargs int do_gang(string str,object me);
varargs int do_peng(string str,object me);
string check_id(string str,string kind);
string do_delete_Mj(string datastr,string str,int amount);
string show_mj(string str,int flag);
string sort_data(string str);
mixed do_check_num(string str,int flag);
//��ֻ����
string MjE= "1w2w3w4w5w6w7w8w9w1t2t3t4t5t6t7t8t9t1s2s3s4s5s6s7s8s9seasowenojofabaf1f2f3f4f5f6f7f8";
string *MjC = ({"",
				"һ��","����","����","����","����","����","����","����","����",
				"һͲ","��Ͳ","��Ͳ","��Ͳ","��Ͳ","��Ͳ","��Ͳ","��Ͳ","��Ͳ",
				"һ��","����","����","����","����","����","����","����","����",
				"����","�Ϸ�","����","����","����","�෢","�װ�",
				"1 ��","2 ��","3 ��","4 ��","1 ÷","2 ��","3 ��","4 ��","����"
				});
string* TossPic = ({
"����"HBWHT BLK"�q�������r"NOR,"����"HBWHT BLK"�q�������r"NOR,"����"HBWHT BLK"�q�������r"NOR,
"����"HBWHT BLK"�t�������s"NOR,"����"HBWHT BLK"�t�������s"NOR,"����"HBWHT BLK"�t�������s"NOR,
"��",
"����"HBWHT BLK"����������"NOR,"����"HBWHT BLK"����"HIR"��"BLK"��"NOR,"����"HBWHT BLK"����������"NOR,
"����"HBWHT BLK"�����񡡩�"NOR,"����"HBWHT BLK"����������"NOR,"����"HBWHT BLK"�����񡡩�"NOR,
"����"HBWHT BLK"���񡡡���"NOR,"����"HBWHT BLK"�����񡡩�"NOR,"����"HBWHT BLK"��������"NOR,
"����"HBWHT BLK"��"HIR"�񡡡�"BLK"��"NOR,"����"HBWHT BLK"����������"NOR,"����"HBWHT BLK"��"HIR"�񡡡�"BLK"��"NOR,
"����"HBWHT BLK"���񡡡�"NOR,"����"HBWHT BLK"�����񡡩�"NOR,"����"HBWHT BLK"���񡡡�"NOR,
"����"HBWHT BLK"���񡡡�"NOR,"����"HBWHT BLK"���񡡡�"NOR,"����"HBWHT BLK"���񡡡�"NOR,
	});

int K;
string Tc = "";
//����
int Auto;
int Auto_Ting;
int Auto_Gang;
int Auto_Peng;
int Count;
int count;
int end;
int Ganged;
int HU_F;
int NO_HU;
int NO_GON;
int Playing;
int Play;
int Times;
int Touched;
int NowPlayer;
string List ="";
string LookP ="";
string *NowPlayerId = ({ "","","","" });
string *NowPlayerName = ({ "","","","" });
string LastDumpId="";
string LastDumpName="";
string LastDump="";
string KaiMen="";
string Dump="";
 
mapping P1Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGang": "","OutPeng": "",
"OutFlower": "","Auto": "","AutoTing": "","AutoGang": "","AutoPeng": "","Dump": ""
               ]);
mapping P2Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGang": "","OutPeng": "",
"OutFlower": "","Auto": "","AutoTing": "","AutoGang": "","AutoPeng": "","Dump": ""
               ]);
mapping P3Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGang": "","OutPeng": "",
"OutFlower": "","Auto": "","AutoTing": "","AutoGang": "","AutoPeng": "","Dump": ""
               ]);
mapping P4Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGang": "","OutPeng": "",
"OutFlower": "","Auto": "","AutoTing": "","AutoGang": "","AutoPeng": "","Dump": ""
               ]);
void create()
{
	set_name(MAG"С��"NOR,({"xiao si" , "xiaosi"}));
	set("gender", "����");
	set("age", 18);
	set_weight(1);
	set("long", "�����齫�ݴ��ӵ�С�ˣ��������齫���淨������Ϥ�Ļ���\n���������������淨�����\n");
	set("inquiry",([
		"������": "�Ҽ���ү���Է�����",
		"mj": "����help mj���˽��齫����ʷ",
		"�齫": "����help mj���˽��齫����ʷ",
		"�淨": "����help playmj���˽��������ָ��",
		"play": "����help playmj���˽��������ָ��",
		"����": (: to_say_rule :),
		"rule": (: to_say_rule :),
	]));
	setup();
	seteuid(getuid());
}
void init()
{
	add_action("do_addin","jiaru");
	add_action("do_addin","addin");
	add_action("do_dump","dump");
	add_action("do_dump","da");
	add_action("do_eat","chi");
	add_action("do_eat","eat");
	add_action("do_gang","gang");
	add_action("do_gang","g");
	add_action("do_win","hu");
	add_action("do_help","help");
	add_action("do_look","look");
	add_action("do_touch","mo");
	add_action("do_peng","peng");
	add_action("do_peng","p");
	add_action("do_restart","restart");
	add_action("wash_mj","wash");
	add_action("do_setmj","setmj");
	add_action("show_score","mjscore");
}
int do_addin()
{
	object me=this_player();
	if (me->query("id")==P1Data["Id"]
		||  me->query("id")==P2Data["Id"]
		||  me->query("id")==P3Data["Id"]
		||  me->query("id")==P4Data["Id"])
	{
		if (!Playing) message_vision(HIY"$N�����齫�����롸��ô������ʼ�ء���\n"NOR,me);
		else switch (random(6))
		{
			case 0: message_vision("\n$N���Ŵ��˵����������������"+chinese_number(random(12)+1)+"�ξͺá���\n",me); break;
			case 1: message_vision("\n$N��ָһ���Ц��˵�����١��١��١����㵽�����һ���ׯ"+chinese_number(random(7)+5)+"�Ρ���\n",me);
					message_vision(HIY"ͻȻ$N����ׯ��Խ��η������ҲԽ........�ء��ء��ء��ء�������\n"NOR,me); break;
			case 2: message_vision("\n$N����"+NowPlayerName[NowPlayer]+"˵�������������������ô������\n",this_object()); break;
			case 3: message_vision(HIY"\n$N���š�����������Ԫ������ϲ����һɫ���尵�̣�����������һ�Ӿ�ÿ������"+chinese_number(40)+"̨����\n"NOR,me); break;
			case 4: message_vision("\n$N����"+NowPlayerName[NowPlayer]+"˵���������������ƻ��������㣿��\n",me); break;
			case 5: message_vision("\n$N���Ŵ�Ұ�������������а�ʮ��ĸ�����ж�Ů��Ⱥ������������Ӯ����\n",me); break;
			case 6: message_vision("\n$N�ĵ�˵���������ϼ�ι�¼ң���Ҫ���ƾ��๫����һ�����һ�ҿ��������㡣��\n",me); break;
		}
		return 1;
	}
	if (Playing)
	{
		switch (random(5))
		{
			case 0: message_vision("\n$N�޿������˵������ҲҪ����.....����\n",me); break;
			case 1: message_vision("\n$N��ҷ߷ߵ�˵�������������Ҿ͡��������Ҿ͡��������Ҿ��������ǿ�����\n"NOR,me); break;
			case 2: message_vision("\n$N����$n˵�������ȳ�ȥת����Ȧ�����ɡ���\n",this_object(),me); break;
			case 3: message_vision("\n$N˵������һ�첻���齫�ͻ����������\n",me); break;
			case 4: message_vision("\n$N����$n˵�������ƾ����ڽ����У��뵽�Ա���һ�¡���\n",this_object(),me); break;
			case 5: message_vision("\n$N���Ŵ��˵��������Ҫ��ʲô���Ҹ�������ȥ����\n",me); break;
		}
		return 1;
	}
	if (!P1Data["Id"] || P1Data["Id"]=="")
	{
		P1Data["Id"]=me->query("id");
		P1Data["Name"]=me->query("name");
		NowPlayerId[Play]=me->query("id");
		NowPlayerName[Play]=me->query("name");
		message_vision("\n��$N���������ⳡ�ƾ֡�\n",me);
		if (me->query_temp("apply/short")) me->set_temp("mj/short", me->query_temp("apply/short"));
		me->set_temp("apply/short", ({"���齫�е�"+me->query("name")+"("+me->query("id")+")"}));
		me->set_temp("���齫��", 1);
		Play++;
		Times=0;
		LookP+="��ǰ����"+me->name()+"��";
		return 1;
	}
	else if (!P2Data["Id"] || P2Data["Id"]=="")
	{
		P2Data["Id"]=me->query("id");
		P2Data["Name"]=me->query("name");
		message_vision("\n��$N���������ⳡ�ƾ֡�\n",me);
		NowPlayerId[Play]=me->query("id");
		NowPlayerName[Play]=me->query("name");
		if (me->query_temp("apply/short")) me->set_temp("mj/short", me->query_temp("apply/short"));
		me->set_temp("apply/short", ({"���齫�е�"+me->query("name")+"("+me->query("id")+")"}));
		me->set_temp("���齫��", 1);
		Play++;
		Times=0;
		LookP+=me->name()+"��";
		return 1;
	}
	else if (!P3Data["Id"] || P3Data["Id"]=="")
	{
		P3Data["Id"]=me->query("id");
		P3Data["Name"]=me->query("name");
		message_vision("\n��$N���������ⳡ�ƾ֡�\n",me);
		NowPlayerId[Play]=me->query("id");
		NowPlayerName[Play]=me->query("name");
		if (me->query_temp("apply/short")) me->set_temp("mj/short", me->query_temp("apply/short"));
		me->set_temp("apply/short", ({"���齫�е�"+me->query("name")+"("+me->query("id")+")"}));
		me->set_temp("���齫��", 1);
		Play++;
		Times=0;
		LookP+=me->name()+"��";
		return 1;
	}
	else if (!P4Data["Id"] || P4Data["Id"]=="")
	{
		P4Data["Id"]=me->query("id");
		P4Data["Name"]=me->query("name");
		message_vision("\n��$N���������ⳡ�ƾ֡�\n",me);
		NowPlayerId[Play]=me->query("id");
		NowPlayerName[Play]=me->query("name");
		if (me->query_temp("apply/short")) me->set_temp("mj/short", me->query_temp("apply/short"));
		me->set_temp("apply/short", ({"���齫�е�"+me->query("name")+"("+me->query("id")+")"}));
		me->set_temp("���齫��", 1);
		Play++;
		Times=0;
		LookP+=me->name();
		message_vision("\n\n$N"CYN"˵�������������㣬��ϴ��"NOR RED"<wash>"NOR CYN"����\n"NOR,this_object());
		return 1;
	}
	return notify_fail(HIW"�������㡣\n"NOR);
}
int do_autodump(string str,object me)
{
	int check,i;
	int *winner=({0,0,0,0});
	string pengid;
	mapping who;
	object met;
 
	if (Ganged==5)
	{
		message_vision("\n��"HIR"��ܺ���"NOR"�����������¿�ʼ"RED"<start>"NOR"��\n",this_object());
		Playing=0;
		Count++;
		if (Play==4)
		{
			for (i=0;i<Play;i++)
			{
				met=present(NowPlayerId[i], environment(this_object()));
				if (!met) met=find_player(NowPlayerId[i]);
				if (!met);
				else
				{
					if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
					winner[0]++;
					set_mjdata(met,winner);
				}
			}
		}
		return 1;
	}
	NO_HU=0;
	HU_F=0;
	NO_GON=0;
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	check=do_check_Mj(MjE,str);
	if (check==0) return notify_fail(HIW"û�С�"NOR HIY+str+NOR HIW"�����ִ��롣\n"NOR);
	check=do_check_Mj(who["Mj"],str);
	if (check==0) return notify_fail(HIW"��û��"NOR HIY+do_check_num(str,0)+NOR HIW"�������ơ�\n"NOR);
	message_vision("\n$N˵������"MAG+do_check_num(str,0)+NOR"��\n",me);
	who["Mj"]=do_delete_Mj(who["Mj"],str,1);
	LastDump=str;
	who["Dump"]+=str;
	LastDumpId=who["Id"];
	LastDumpName=who["Name"];
	Touched=0;
	NowPlayer++;
	NowPlayer%=Play;
	message_vision("\n�����ֵ���"HIY+NowPlayerName[NowPlayer]+NOR"�����ơ�\n",this_object());
	if (Auto_Ting)
	{
		pengid=check_id(str,"ting");
		if (pengid!="")
		{
			me=present(pengid, environment(this_object()));
			if (!me) me=find_player(pengid);
			if (!me) return 1;
			return do_win(str,me);
		}
	}
	if (Auto_Gang)
	{
		pengid=check_id(str,"gang");
		if (pengid!="")
		{
			me=present(pengid, environment(this_object()));
			if (!me) me=find_player(pengid);
			if (!me) return 1;
			do_gang(str,me);
		}
	}
	if (Auto_Peng)
	{
		pengid=check_id(str,"peng");
		if (pengid!="")
		{
			me=present(pengid, environment(this_object()));
			if (!me) me=find_player(pengid);
			if (!me) return 1;
			do_peng(str,me);
		}
	}
	if (count==(end-16-Ganged))
	{
		Playing=0;
		Count++;
		message_vision("\n��"RED"����"NOR"���������¿�ʼ "HIR"<start>"NOR" ��\n",this_object());
		str="��ʣ�µ���ֻ�У���"+show_mj(List[count..end],2)+"��\n";
		tell_room(environment(this_object()),str);
		if (Play==4)
		{
			for (i=0;i<Play;i++)
			{
				met=present(NowPlayerId[i], environment(this_object()));
				if (!met) met=find_player(NowPlayerId[i]);
				if (!met);
				else
				{
				if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
				winner[0]++;
				set_mjdata(met,winner);
				}
			}
		}
		return 1;
	}
	if (Auto)
	{
		if (NowPlayerId[NowPlayer]==P1Data["Id"]) who=P1Data;
		else if (NowPlayerId[NowPlayer]==P2Data["Id"]) who=P2Data;
		else if (NowPlayerId[NowPlayer]==P3Data["Id"]) who=P3Data;
		else if (NowPlayerId[NowPlayer]==P4Data["Id"]) who=P4Data;
		if (who["Auto"]=="auto")
		{
			me=present(NowPlayerId[NowPlayer], environment(this_object()));
			if (!me) me=find_player(NowPlayerId[NowPlayer]);
			if (!me) return 1;
			call_out("do_touch",4,"AUTO",me);
		}
	}
	return 1;
}
int do_dump(string str,object me)
{
	int check,i;
	int *winner=({0,0,0,0});
	string pengid;
	mapping who;
	object met;
 
	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else return notify_fail(HIW"���ƾָ���û��ϵ��\n"NOR);
	if (!Playing) return notify_fail(HIW"���ƾָ���û��ϵ��\n"NOR);
	if (!str) return notify_fail(HIW"ָ�da <����>\n"NOR);
	if (me->query("id")!=NowPlayerId[NowPlayer])
	{
		message_vision("�������ֵ���"HIY+NowPlayerName[NowPlayer]+NOR"��\n",me);
		return notify_fail(HIW"���װ����������ֵ���"NOR HIY+NowPlayerName[NowPlayer]+NOR HIW"�������㣬��͵���ƣ���\n"NOR);
	}
	if (!Touched) return notify_fail(HIW"�㻹û���ƣ���\n"NOR);
	if (Ganged==5)
	{
		message_vision("\n��"HIR"��ܺ���"NOR"�����������¿�ʼ"RED"<start>"NOR"��\n",this_object());
		Playing=0;
		Count++;
		if (Play==4)
		{
			for (i=0;i<Play;i++)
			{
				met=present(NowPlayerId[i], environment(this_object()));
				if (!met) met=find_player(NowPlayerId[i]);
				if (!met);
				else
				{
					if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
					winner[0]++;
					set_mjdata(met,winner);
				}
			}
		}
		return 1;
	}
	NO_HU=0;
	HU_F=0;
	NO_GON=0;
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (who["Auto"]=="auto") return notify_fail(HIW"�����ᣬ�����Լ����ơ�\n"NOR);
	if (who["Auto"]=="dump") who["Auto"]="auto";
	check=do_check_Mj(MjE,str);
	if (check==0) return notify_fail(HIW"û�С�"NOR HIY+str+NOR HIW"�����ִ��롣\n"NOR);
	check=do_check_Mj(who["Mj"],str);
	if (check==0) return notify_fail(HIW"��û��"NOR HIY+do_check_num(str,0)+NOR HIW"�������ơ�\n"NOR);
	message_vision("\n$N˵������"MAG+do_check_num(str,0)+NOR"��\n",me);
	who["Mj"]=do_delete_Mj(who["Mj"],str,1);
	LastDump=str;
	who["Dump"]+=str;
	LastDumpId=who["Id"];
	LastDumpName=who["Name"];
	Touched=0;
	NowPlayer++;
	NowPlayer%=Play;
	message_vision("\n�����ֵ���"HIY+NowPlayerName[NowPlayer]+NOR"�����ơ�\n",this_object());
	if (Auto_Ting)
	{
		pengid=check_id(str,"ting");
		if (pengid!="")
		{
			me=present(pengid, environment(this_object()));
			if (!me) me=find_player(pengid);
			if (!me) return 1;
			return do_win(str,me);
		}
	}
	if (Auto_Gang)
	{
		pengid=check_id(str,"gang");
		if (pengid!="")
		{
			me=present(pengid, environment(this_object()));
			if (!me) me=find_player(pengid);
			if (!me) return 1;
			do_gang(str,me);
		}
	}
	if (Auto_Peng)
	{
		pengid=check_id(str,"peng");
		if (pengid!="")
		{
			me=present(pengid, environment(this_object()));
			if (!me) me=find_player(pengid);
			if (!me) return 1;
			do_peng(str,me);
		}
	}
	if (count==(end-16-Ganged))
	{
		Playing=0;
		Count++;
		message_vision("\n��"RED"����"NOR"���������¿�ʼ "HIR"<start>"NOR" ��\n",this_object());
		str="��ʣ�µ���ֻ�У���"+show_mj(List[count..end],2)+"��\n";
		tell_room(environment(this_object()),str);
		if (Play==4)
		{
			for (i=0;i<Play;i++)
			{
				met=present(NowPlayerId[i], environment(this_object()));
				if (!met) met=find_player(NowPlayerId[i]);
				if (!met);
				else
				{
				if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
				winner[0]++;
				set_mjdata(met,winner);
				}
			}
		}
		return 1;
	}
	if (Auto)
	{
		if (NowPlayerId[NowPlayer]==P1Data["Id"]) who=P1Data;
		else if (NowPlayerId[NowPlayer]==P2Data["Id"]) who=P2Data;
		else if (NowPlayerId[NowPlayer]==P3Data["Id"]) who=P3Data;
		else if (NowPlayerId[NowPlayer]==P4Data["Id"]) who=P4Data;
		if (who["Auto"]=="auto")
		{
			me=present(NowPlayerId[NowPlayer], environment(this_object()));
			if (!me) me=find_player(NowPlayerId[NowPlayer]);
			if (!me) return 1;
			call_out("do_touch",4,"AUTO",me);
		}
	}
	return 1;
}
int do_eat(string str)
{
	int LastDumpMan,i;
	string num1,num2;
	object me=this_player();
	mapping who;
 
	if (!str || sscanf(str,"%s %s",num1,num2)!=2) return 0;
	if (check_id(me->query("id"),"player")!="");
	else
	{
		tell_object(me,HIW"���ƾָ���û��ϵ��\n"NOR);
		return 1;
	}
	if (!Playing)
	{
		tell_object(me,HIW"�ƾֻ�û��ʼ��\n"NOR);
		return 1;
	}
	if (me->query("id")!=NowPlayerId[NowPlayer])
	{
		tell_object(me,HIW"��û�ֵ��㣡�������ֵ���"NOR HIY+NowPlayerName[NowPlayer]+NOR HIW"����\n"NOR);
		return 1;
	}
	if (!LastDump || LastDump=="")
	{
		tell_object(me,HIW"���ưɡ�\n"NOR);
		return 1;
	}
	if (Touched)
	{
		tell_object(me,HIW"����������\n"NOR);
		return 1;
	}
	if (do_check_eat(num1,num2,LastDump)==0)
	{
		tell_object(me,HIW"���۾����˰���������Ҳ�ܳԡ�\n"NOR);
		return 1;
	}
	if (num1==num2)
	{
		tell_object(me,HIW"��ͬ���Ʋ��ܳԡ�\n"NOR);
		return 1;
	}	
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	LastDumpMan=do_check_Mj(MjE,num1);
	if (LastDumpMan==0) return notify_fail(HIW"û�С�"NOR HIY+num1+NOR HIW"�����ִ��롣\n"NOR);
	LastDumpMan=do_check_Mj(MjE,num2);
	if (LastDumpMan==0) return notify_fail(HIW"û�С�"NOR HIY+num2+NOR HIW"�����ִ��롣\n"NOR);
	LastDumpMan=do_check_Mj(who["Mj"],num1);
	if (LastDumpMan==0) return notify_fail(HIW"��û��"NOR HIY+do_check_num(num1,0)+NOR HIW"�������ơ�\n"NOR);
	LastDumpMan=do_check_Mj(who["Mj"],num2);
	if (LastDumpMan==0) return notify_fail(HIW"��û��"NOR HIY+do_check_num(num2,0)+NOR HIW"�������ơ�\n"NOR);
	message_vision("\n$N�ó���һ�š�"YEL+do_check_num(num1,0)+NOR"����һ�š�"HIY+do_check_num(num2,0)+NOR"�������ˡ�"HIR+do_check_num(LastDump,0)+NOR"����\n\n",me);
	who["Out"]+=num2;
	who["Out"]+=LastDump;
	who["Out"]+=num1;
	who["Mj"]=do_delete_Mj(who["Mj"],num1,1);
	who["Mj"]=do_delete_Mj(who["Mj"],num2,1);
	Touched=1;
	NO_HU=1;
	NO_GON=1;
	i=0;
	if (who["Show"]=="����") i=3;
	if (who["Show"]=="color") i=5;
	tell_object(me,show_mj(who["Mj"],i));
	return delete_last_dump(who["Id"]);
}
int do_gang(string str,object me)
{
	int i;
	mapping who;
 
	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else return notify_fail(HIW"���ƾָ���û��ϵ��\n"NOR);
	if (!Playing) return notify_fail(HIW"�ƾֻ�û��ʼ����\n"NOR);
	if (LastDumpId==me->query("id")) return notify_fail(HIW"�����������Լ���ģ�\n"NOR);
	if (Touched && NowPlayerId[NowPlayer]!=me->query("id")) return notify_fail(HIW"����û����������ܣ�\n"NOR);
	
	if (!str) str=LastDump;
 	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (who["Auto"]=="auto") return 1;
	i=do_check_Mj(who["Mj"],str);
	if (i==1)
	{
		if (!Touched) return notify_fail(HIW"�㻹û���ơ�\n"NOR);
		i=do_check_Mj(who["OutPeng"],str);
		if (!i) return notify_fail(HIW"��ֻ��һ�Ų��ܸܡ�\n"NOR);
		if (NO_GON) return notify_fail(HIW"�����޷����ơ�\n"NOR);
		switch (random(5))
		{
			case 0: message_vision("\n$N��У���"HIB"ľ��"NOR WHT"������������"NOR"��\n\n",me); break;
			case 1: message_vision("\n$N��У���"HIB"ľ��"NOR WHT"������������"NOR"��\n\n",me); break;
			case 2: message_vision("\n$Nϲ������������Ҳ����������"WHT"�ڹ���С�����"NOR HIB"ľ��������"NOR"��\n\n",me); break;
			case 3: message_vision("\n$Nϲ������������Ҳ����������"WHT"�ڹ���С�����"NOR HIB"ľ��������"NOR"��\n\n",me); break;
			case 4: message_vision("\n$N��Ц������"HIB"ľ��"NOR WHT"������������"NOR"���Ҹ��Ͽ�����\n\n",me); break;
			case 5: message_vision("\n$N��Ц������"HIB"ľ��"NOR WHT"������������"NOR"���Ҹ��Ͽ�����\n\n",me); break;
		}
		who["Mj"]=do_delete_Mj(who["Mj"],str,1);
		sort_data(who["OutPeng"]+=str);
		str=List[end..end+1];
		end-=2;
		Ganged++;
		message_vision("\n$N�����油��һ���ơ�\n\n",me);
		tell_object(me,"�㲹��һ�š�"HIY+do_check_num(str,0)+NOR"��\n");
		i=0;
		if (who["Show"]=="����") i=3;
		if (who["Show"]=="color") i=5;
		who["Mj"]+=str;
		check_flower(who);
		tell_object(me,show_mj(who["Mj"],i));
		Touched=1;
		return 1;
	}
	if (i < 3) return notify_fail(HIW"������Ҫ�����š�"NOR HIY+do_check_num(str,0)+NOR HIW"�����ܸܡ�\n"NOR);
	if (!Touched)
	{
		if (str!=LastDump) return notify_fail("�����޷��ܡ�\n");
	}
	else if (i < 4) return notify_fail(HIW"������Ҫ�����š�"NOR HIY+do_check_num(str,0)+NOR HIW"�����ܰ��ܡ�\n"NOR);
	for (i=0;i<Play;i++)
	{
		if (NowPlayerId[NowPlayer]==me->query("id")) break;
		NowPlayer++;
		NowPlayer%=Play;
	}
	who["Mj"]=do_delete_Mj(who["Mj"],str,3);
	if (Touched && NowPlayerId[NowPlayer]==me->query("id"))
	{
		NO_HU=0;
		switch (random(5))
		{
			case 0: message_vision("\n$N����¶��а���Ц��˵������"HIR"����ľ������"NOR HIC"���ںڿںڡ���"NOR"��\n\n",me); break;
			case 1: message_vision("\n$N����¶��а���Ц��˵������"HIR"����ľ������"NOR HIC"���ںڿںڡ���"NOR"��\n\n",me); break;
			case 2: message_vision("\n$N�ھε�˵������ϣ���������Ĳ�����һֻ���ҡ�"HIR"����ľ������"NOR"��\n\n",me); break;
			case 3: message_vision("\n$N�ھε�˵������ϣ���������Ĳ�����һֻ���ҡ�"HIR"����ľ������"NOR"��\n\n",me); break;
			case 4: message_vision("\n$N���ȵĽе�����"MAG"�ڹ�ںϣ�"NOR"�Ҷ�һ̨��"HIR"������ľ������"NOR"��\n\n",me); break;
			case 5: message_vision("\n$N���ȵĽе�����"MAG"�ڹ�ںϣ�"NOR"�Ҷ�һ̨��"HIR"������ľ������"NOR"��\n\n",me); break;
		}
		who["Mj"]=do_delete_Mj(who["Mj"],str,1);
		for (i=0;i<4;i++) who["Out"]+="xx";
		for (i=0;i<4;i++) who["OutGang"]+=str;
	}
	else
	{
		NO_HU=1;
		switch (random(5))
		{
			case 0: message_vision("\n$N�ܴ�����˵������"GRN+do_check_num(str,0)+"����"NOR HIW+"��ľ��������"NOR"��\n\n",me); break;
			case 1: message_vision("\n$N�ܴ�����˵������"GRN+do_check_num(str,0)+"����"NOR HIW+"��ľ��������"NOR"��\n\n",me); break;
			case 2: message_vision("\n$N�е�����"WHT"�ڹ���С�����"NOR GRN+do_check_num(str,0)+NOR"����"HIW+"��ľ��������"NOR"��\n\n",me); break;
			case 3: message_vision("\n$N�е�����"WHT"�ڹ���С�����"NOR GRN+do_check_num(str,0)+NOR"����"HIW+"��ľ��������"NOR"��\n\n",me); break;
			case 4: message_vision("\n$N��������"GRN+do_check_num(str,0)+NOR"�ҡ�"HIW+"ľ��������"NOR"��\n\n",me); break;
			case 5: message_vision("\n$N��������"GRN+do_check_num(str,0)+NOR"�ҡ�"HIW+"ľ��������"NOR"��\n\n",me); break;
		}
		for (i=0;i<4;i++) who["Out"]+=str;
	}
	str=List[end..end+1];
	end-=2;
	Ganged++;
	message_vision("$N�����油��һ���ơ�\n",me);
	tell_object(me,"�㲹��һ�š�"HIY+do_check_num(str,0)+NOR"��\n");
	who["Mj"]+=str;
	check_flower(who);
	i=0;
	if (who["Show"]=="����") i=3;
	if (who["Show"]=="color") i=5;
	tell_object(me,show_mj(who["Mj"],i));
	if (Touched) return 1;
	Touched=1;
	return delete_last_dump(who["Id"]);
}
varargs int do_win(string str,object me)
{
	int i,j;
	int *winner=({0,0,0,0});
	string Mj="";
	mapping who;
	object met, room=find_object("/u/mantian/mjroom.c");

	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else return notify_fail(HIW"���ƾָ���û��ϵ��\n"NOR);
	if (!Playing) return notify_fail(HIW"�ƾֻ�û��ʼ����\n"NOR);
	if (NO_HU || LastDumpId==me->query("id")) return notify_fail(HIW"�������ܺ��ơ�\n"NOR);
	if (LastDump==""&&Touched) message_vision("\n$N��У���"WHT"�졫������������������������"NOR"��\n\n",me);
	else message_vision("$N��У���"WHT"�ҡ���������������������������������������"NOR"��\n\n",me);
	if (Touched&&NowPlayerId[NowPlayer]==me->query("id"))
	message_vision("$N˵����������"+me->name()+HIM"����"NOR"����������������\n",this_object());
	else command("say "+me->name()+"����");
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (sizeof(who["OutFlower"]) ==16) i=1;
	else if (sizeof(who["OutFlower"]) ==14&&sizeof(P1Data["OutFlower"]+P2Data["OutFlower"]+P3Data["OutFlower"]+P4Data["OutFlower"])==16) i=1;
	if (!HU_F) i=0;
	if (i)
	{
		Mj+="���ҵĻ����ǣ�\n";
		Mj+=show_mj(who["OutFlower"],1);
		if (NowPlayerId[NowPlayer]==who["Id"]) Mj+="���һ�������\n";
		else
		{
			if (sizeof(P1Data["OutFlower"])==2) LastDumpId=P1Data["Id"];
			else if (sizeof(P2Data["OutFlower"])==2) LastDumpId=P2Data["Id"];
			else if (sizeof(P3Data["OutFlower"])==2) LastDumpId=P3Data["Id"];
			else if (sizeof(P4Data["OutFlower"])==2) LastDumpId=P4Data["Id"];
			Mj+="\n���Ʒ�ǹ�ߣ���"HIB+LastDumpName+NOR"��\n";
		}
	}
	else
	{
		Mj+="���ҵ����ǣ�\n";
		if (who["OutGang"]!="")
		{
			Mj+="���ܵ��У�\n";
			Mj+=show_mj(who["OutGang"],0);
		}
		Mj+=who["Id"]+"�����е����У�\n";
		if (!Touched)
		{
			who["Mj"]+=LastDump;
			who["Mj"]=sort_data(who["Mj"]);
			Mj+=show_mj(who["Mj"],0);
			Mj+="���������ǣ���"HIR+do_check_num(LastDump,0)+NOR"��";
			Mj+="\n��ǹ�ߣ���"HIB+LastDumpName+NOR"��\n";
		}
		else
		{
			Mj+=show_mj(who["Mj"],0);
			if (str) Mj+="�����������ǣ���"HIR+do_check_num(str,0)+NOR"��\n";
		}
	}
	Playing=0;
	tell_room(environment(this_object()),Mj);
	Tc="";
	if (do_check_win(who["Mj"])==1||i==1)
	{
//��̨///////////////////////////////////
	mixed MjT = ([
	"@1" : ({ "ׯ��", 1 }),	"@2" : ({ "����", 1 }),	"@3" : ({ "����", 1 }),	"@4" : ({ "����", 1 }),
	"@5" : ({ "����", 1 }),	"@6" : ({ "�Ϸ�", 1 }),	"@7" : ({ "����", 1 }),	"@8" : ({ "����", 1 }),
	"@9" : ({ "����", 1 }),	"@0" : ({ "�෢", 1 }),	"@a" : ({ "�װ�", 1 }),	"@G" : ({ "һا��", 1 }),
	"@b" : ({ "��������", 1 }),	"@c" : ({ "����", 1 }),	"@d" : ({ "ƽ��", 2 }),	"@e" : ({ "���綫", 2 }),
	"@f" : ({ "�Ϸ���", 2 }),	"@g" : ({ "������", 2 }),	"@h" : ({ "���籱", 2 }),	"@i" : ({ "ȫ����", 2 }),
	"@j" : ({ "������", 2 }),	"@H" : ({ "��ا��", 2 }),	"@k" : ({ "������", 2 }),	"@B" : ({ "�����ﶬ", 2 }),
	"@C" : ({ "÷������", 2 }),	"@l" : ({ "��������", 3 }),	"@m" : ({ "������", 4 }),	"@n" : ({ "��һɫ", 4 }),
	"@o" : ({ "С��Ԫ", 4 }),	"@p" : ({ "�İ���", 5 }),	"@q" : ({ "��һɫ", 8 }),	"@r" : ({ "��һɫ", 8 }),
	"@s" : ({ "�߶���", 8 }),	"@t" : ({ "����Ԫ", 8 }),	"@u" : ({ "�尵��", 8 }),	"@F" : ({ "С��ϲ", 8 }),
	"@D" : ({ "����һ", 8 }),	"@E" : ({ "��һɫ", 8 }),	"@v" : ({ "����ϲ", 16 }),	"@w" : ({ "���", 16 }),
	"@x" : ({ "�غ�", 16 }),	"@y" : ({ "�˺�", 16 }),	"@z" : ({ "��ʿ��˫", 16 }),
	"@A" : ({ "���ɹ���", 8 }),	"@J" : ({ "����ͷ", 8 }),	"@I" : ({ "����ͷ", 4 }),
	]);//H
	get_tc(who);
////////////////
		str="\t\t\t�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n";
		for (i=0;i<sizeof(Tc);i+=2)
		{
			str+=sprintf("\t\t\t%-12s%8s ̨\n",MjT[Tc[i..i+1]][0],chinese_number(MjT[Tc[i..i+1]][1]));
			j+=MjT[Tc[i..i+1]][1];
		}
		if (Count)
		{
			str+=sprintf("\t\t\t%-12s%8s ̨\n","��"+chinese_number(Count)+"��"+chinese_number(Count),chinese_number(Count*2));
			j+=Count*2;
		}
		str+=sprintf("\t\t\t%20s\n","��̨����"+chinese_number(j+5)+" ̨");
		str+="\t\t\t�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n";
		tell_room(environment(this_player()),str);
/////////////
		if (!Touched)
		{
			if (Play==4)
			{
				if (!winner=get_mjdata(me->query("id"))) winner=({0,0,0,0});
				winner[1]+=j;
				set_mjdata(me,winner);
				met=present(LastDumpId, environment(this_object()));
				if (!met) met=find_player(LastDumpId);
				if (!met);
				else
				{
					if (!winner=get_mjdata(LastDumpId)) winner=({0,0,0,0});
					winner[1]-=j;//ս��
					winner[3]++;//��ǹ
					set_mjdata(met,winner);
				}
				for (i=0;i<Play;i++)
				{
					met=present(NowPlayerId[i], environment(this_object()));
					if (!met) met=find_player(NowPlayerId[i]);
					if (!met);
					else
					{
						if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
						winner[0]++;//����
						set_mjdata(met,winner);
					}
				}
			}
		}
		else
		{
			if (Play==4)
			{
				if (!winner=get_mjdata(me->query("id"))) winner=({0,0,0,0});
				winner[0]++;
				winner[1]+=(j*3);
				winner[2]++;
				set_mjdata(me,winner);
				for (i=0;i<Play;i++)
				{
					if (NowPlayerId[i]==me->query("id")) continue;
					met=present(NowPlayerId[i], environment(this_object()));
					if (!met) met=find_player(NowPlayerId[i]);
					if (!met);
					else
					{
						if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
						winner[0]++;
						winner[1]-=j;
						set_mjdata(met,winner);
					}
				}
			}
		}
		if (NowPlayerId[0]==who["Id"]) Count++;
		else
		{
			Times++;
			Count=0;
		}
	}
	else
	{
		command("sigh "+who["Id"]);
		message_vision(CYN"$N˵��������� ["NOR HIR+who["Id"]+NOR CYN"]������է�� ���¡���������\n"NOR,this_object());
		Times++;
		Count=0;
		if (Play==4)
		{
			if (!winner=get_mjdata(me->query("id"))) winner=({0,0,0,0});
			if (NowPlayerId[NowPlayer]==who["Id"]&&Touched)
			{
				if (who["Out"]==""&&who["OutPeng"]=="")
				{
					winner[1]-=24;
					j=-24;
				}
				else
				{
					winner[1]-=18;
					j=-18;
				}
			}
			else
			{
				if (who["Out"]==""&&who["OutPeng"]=="")
				{
					winner[1]-=6;
					j=-6;
				}
				else
				{
					winner[1]-=5;
					j=-5;
				}
			}
////////////////
			str="\t\t\t�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n";
			str+=sprintf("\t\t\t%-12s%8s ̨\n","թ��",chinese_number(j));
			str+=sprintf("\t\t\t%20s\n","��̨����"+chinese_number((j+5)*3)+" ̨");
			str+="\t\t\t�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n";
			tell_room(environment(this_player()),str);
/////////////
			set_mjdata(me,winner);
			for (i=0;i<Play;i++)
			{
				met=present(NowPlayerId[i], environment(this_object()));
				if (!met) met=find_player(NowPlayerId[i]);
				if (!met);
				else
				{
					if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
					winner[0]++;
					set_mjdata(met,winner);
				}
			}
		}
	}
	Mj="\n  ";
	for (i=0; i<26; i++) Mj+="  ";
	Mj+="  \n";
	Mj+="��������"HIW"�������֡������������ս����������������ǹ������\n";
	for (i=0;i<Play;i++)
	{
		if (Play==4) winner=get_mjdata(NowPlayerId[i]);
		Mj+=sprintf("����%12s��%8d��%6d��%8d��%8d  \n",
		NowPlayerId[i],winner[0],winner[1],winner[2],winner[3]);
	}
	Mj+="  ";
	for (i=0; i<26; i++) Mj+="  ";
	Mj+="��\n";
	if (Play==4) tell_room(environment(this_object()),Mj);
	room->delete_temp("mjstart", 1);
	message_vision("\n$N"CYN"˵�������ƾֽ�������ϴ��"NOR RED"<wash>"NOR CYN"������һ�֡���\n"NOR,this_object());
	return 1;
}
int do_check_win(string str)
{
	int size=strlen(str),i,check;
	int t,k,W,T,S,Sp;
	string tempW="",tempT="",tempS="",tempB="";
	string Special="1w9w1s9s1t9teasowenojofaba";
 
	K=0;
	if (size > 33)
	{
		if (do_check_Mj(str,"ea")&&do_check_Mj(str,"so")&&do_check_Mj(str,"we")&&do_check_Mj(str,"no")&&
			do_check_Mj(str,"jo")&&do_check_Mj(str,"fa")&&do_check_Mj(str,"ba")&&do_check_Mj(str,"1w")&&
			do_check_Mj(str,"9w")&&do_check_Mj(str,"1s")&&do_check_Mj(str,"9s")&&do_check_Mj(str,"1t")&&
			do_check_Mj(str,"9t"))
		{//��ɾ��13ֻ
			for (i=0;i<sizeof(Special);i+=2)
			{
				if (do_check_Mj(str,Special[i..i+1]))
				{
					str=do_delete_Mj(str,Special[i..i+1],1);
				}
			}//�黹��û13ô�е���ֻ
			for (i=0;i<sizeof(Special);i+=2)
			{
				if (do_check_Mj(str,Special[i..i+1]))
				{
					Sp++;
				}
			}
			if (Sp==1)
			{
				for (i=0;i<sizeof(Special);i+=2)
				{
				if (do_check_Mj(str,Special[i..i+1]))
					{
						str=do_delete_Mj(str,Special[i..i+1],1);
						t++;
						Tc+="@z";//13ô
					}
				}
			}
			else if (Sp==2)
			{
				for (i=0;i<sizeof(str);i+=2)
				{
				if (do_check_Mj(str,str[i..i+1])==2)
					{
						str=do_delete_Mj(str,str[i..i+1],1);
						Sp=0;
						t++;
					}
				}
				if (Sp!=0)
				{
					if (str[0..1]+1==str[2..3])
					{
						str=do_delete_Mj(str,str[6..7],1);
						t++;
					}
					else
					{
						str=do_delete_Mj(str,str[0..1],1);
						t++;
					}
				}
			}
		}
		else
		{
			for (i=0;i<sizeof(str);i+=2)
			{
				if (do_check_Mj(str,str[i..i+1])==2) Sp++;
				else if (do_check_Mj(str,str[i..i+1])==3) check++;
				else if (do_check_Mj(str,str[i..i+1])==4) Sp++;
			}
			if (Sp==14&&check==3)
			{
				for (i=0;i<sizeof(str);i+=2)
				{
					if (do_check_Mj(str,str[i..i+1])==2)
					{
						str=do_delete_Mj(str,str[i..i+1],2);
						i=-2;
					}
					else if (do_check_Mj(str,str[i..i+1])==4)
					{
						str=do_delete_Mj(str,str[i..i+1],4);
						i=-2;
					}
					else if (do_check_Mj(str,str[i..i+1])==3) t++;
				}
				t=1;
				Tc+="@s";//7����
			}
		}
	}
	while(size--)
	{
		size--;
		if (do_check_num(str[size..size+1],1) < 10) tempW+=str[size..size+1];
		else if (do_check_num(str[size..size+1],1) < 19) tempT+=str[size..size+1];
		else if (do_check_num(str[size..size+1],1) < 28) tempS+=str[size..size+1];
		else tempB+=str[size..size+1];
	}
	if (tempB!="")
	{
		for (i=0;i<strlen(tempB);i+=2)
		{//
			check=do_check_Mj(tempB,tempB[i..i+1]);
			if (check==1) return 0;
			else if (check==2)
			{
				tempB=do_delete_Mj(tempB,tempB[i..i+1],2);
				t++;
				i=-2;
			}
			else if (check==3)
			{
				tempB=do_delete_Mj(tempB,tempB[i..i+1],3);
				K++;
				i=-2;
			}
		}//
	}
	if (tempW!="") W=check_hu(tempW);
	if (tempT!="") T=check_hu(tempT);
	if (tempS!="") S=check_hu(tempS);
	if (K==3) Tc+="@j";//������
	else if (K==4) Tc+="@p";//�İ���
	else if (K==5) Tc+="@u";//�尵��
	if (W+T+S+t==1) return 1;
	return 0;
}
int check_hu(string strW)
{
	int i,j,check;
	int k,t;
	int A,B,C,D,E,F;
	for (i=0;i<sizeof(strW);i+=2)
	{//�ٰ�˳��ɾ��
		A=do_check_num(strW[i..i+1],2);
		B=do_check_num(strW[i+2..i+3],2);
		C=do_check_num(strW[i+4..i+5],2);
		D=do_check_num(strW[i+6..i+7],2);
		E=do_check_num(strW[i+8..i+9],2);
		F=do_check_num(strW[i+10..i+11],2);
		if (sizeof(strW) > 11 &&do_check_num(strW[i-2..i-1],2)!=A&&A+1==B&&B==C&&C+1==D&&D==E&&E+1==F
			||do_check_num(strW[i-2..i-1],2)!=A&&A==B&&B+1==C&&C==D&&D+1==E&&E==F)
		{
			if (A==B&&B+1==C&&C==D&&D+1==E&&E==F)
			{
				if (do_check_Mj(Tc,"@G")==1)
				{
					Tc=do_delete_Mj(Tc,"@H",1);
					Tc+="@H";
				}
				else Tc+="@G";
			}
			for (j=0;j<6;j++)
			{//ɾ��˳��1 22 33 4 && 22 33 44
				strW=do_delete_Mj(strW,strW[i..i+1],1);
			}
			i=-2;
		}
		else if (A+1==B&&B==C&&C==D&&D==E&&E+1==F)
		{
			for (j=0;j<2;j++)
			{//ɾ��˳��1 2 2 2 2 3
				strW=do_delete_Mj(strW,strW[i..i+1],1);
			}
			strW=do_delete_Mj(strW,strW[i+6..i+7],1);
			i=-2;
		}
		else if (sizeof(strW) > 9 && A+1==B&&B==C&&C==D&&D+1==E)
		{//ɾ��˳��12223�е�1 2 3
			strW=do_delete_Mj(strW,strW[i..i+1],1);
			strW=do_delete_Mj(strW,strW[i..i+1],1);
			strW=do_delete_Mj(strW,strW[i+4..i+5],1);
			i=-2;
		}
		else if (sizeof(strW) > 9 && A==B&&B+1==C&&C+1==D&&D+1==E)
		{
			for (j=0;j<3;j++)
			{//ɾ��˳��11234�е�2 3 4
				strW=do_delete_Mj(strW,strW[i+4..i+5],1);
			}
			i=-2;
		}
		else if (sizeof(strW) > 5 && A+1==B&&B+1==C)
		{
			for (j=0;j<3;j++)
			{//ɾ��˳��123�е�1 2 3
				strW=do_delete_Mj(strW,strW[i..i+1],1);
			}
			i=-2;
		}
	}
	if (sizeof(strW) > 5)
	{
		for (i=0;i<sizeof(strW);i+=2)
		{//�ٰѿ�ɾ��
			check=do_check_Mj(strW,strW[i..i+1]);
			if (check==3)
			{
				K++;
				strW=do_delete_Mj(strW,strW[i..i+1],3);
				i=-2;
			}
		}
	}
	for (i=0;i<sizeof(strW);i+=2)
	{//�ٰѶ�ɾ��
		check=do_check_Mj(strW,strW[i..i+1]);
		if (check==2)
		{
			t++;
			strW=do_delete_Mj(strW,strW[i..i+1],2);
			i=-2;
		}
	}
	if (strW!="") return 99;
	return t;
}
int do_touch(string str,object me)
{
	int i,check;
	string pengid;
	mapping who;

	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else return notify_fail(HIW"���ƾָ���û��ϵ��\n"NOR);
	if (!Playing) return notify_fail(HIW"�ƾֻ�û��ʼ��Ҫ����ȥ����������\n"NOR);	
	if (me->query("id")!=NowPlayerId[NowPlayer])
	{
		message_vision("�������ֵ���"HIY+NowPlayerName[NowPlayer]+NOR"��\n",me);
		return notify_fail(HIW"��͵�ƣ�û�������ף����������ֵ���"NOR HIY+NowPlayerName[NowPlayer]+NOR HIW"�������㡣\n"NOR);
	}
	if (Touched) return notify_fail(HIW"����������\n"NOR);	

	NO_HU=0;
	NO_GON=0;
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (who["Auto"]=="auto")
	{
		if (str=="AUTO");
		else
		{
			write(HIW"\n�����ᣬ�����Լ����ơ�\n"NOR);
			return 1;
		}
	}
	Touched=1;
	str=List[count..count+1];
	count+=2;
	message_vision("\n$N����һ���ơ�\n\n",me);
	tell_object(me,"������һ�š�"HIY+do_check_num(str,0)+NOR"��\n");
	if (who["Auto"]=="auto")
	{
		if (do_check_num(str,1) > 34)
		{
			for (i=0;i<1;i++)
			{
				who["OutFlower"]+=str;
				HU_F=1;
				message_vision("\n$N˵������"WHT"����"NOR"����������\n\n$N�����油��һ���ơ�\n\n",me);
				str=List[end..end+1];
				end-=2;
				tell_object(me,"�㲹��һ�š�"HIY+do_check_num(str,0)+NOR"��\n");
				if (do_check_num(str,1) > 34) i--;
			}
		}
		check=do_check_Mj(who["AutoTing"],str);
		if (check!=0)
		{
			who["Mj"]+=str;
			who["Mj"]=sort_data(who["Mj"]);
			return do_win(str,me);
		}
		if (Auto_Gang)
		{
			pengid=check_id(str,"gang");
			if (pengid!="")
			{
				me=present(pengid, environment(this_object()));
				if (!me) me=find_player(pengid);
				if (!me) return 1;
				do_gang(str,me);
			}
		}
		call_out("do_autodump",0,str,me);
	}
	who["Mj"]+=str;
	check_flower(who);
	i=0;
	if (who["Show"]=="����") i=3;
	if (who["Show"]=="color") i=5;
	tell_object(me,show_mj(who["Mj"],i));
	return 1;
}
int do_peng(string str,object me)
{
	int i;
	mapping who;
 
	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else return notify_fail(HIW"���ƾָ���û��ϵ��\n"NOR);
	if (!Playing) return notify_fail(HIW"�ƾֻ�û��ʼ���������ͷ������\n"NOR);	
	if (Touched) return notify_fail(HIW"����û��������������\n"NOR);
	if (LastDumpId==me->query("id")) return notify_fail(HIW"�����������Լ���ģ�\n"NOR);

	if (!str) str=LastDump;
	else if (str!=LastDump) return notify_fail(HIW"���š�"NOR HIY+do_check_num(str,0)+HIW"���Ѿ������ˡ�\n"NOR);
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (who["Auto"]=="auto") return 1;
	i=do_check_Mj(who["Mj"],str);
	if (i==0) return notify_fail(HIW"��û��"NOR HIY+do_check_num(str,0)+NOR HIW"��������Ҫ��������\n"NOR);
	if (i < 2) return notify_fail(HIW"������Ҫ�����š�"NOR HIY+do_check_num(str,0)+NOR HIW"����������\n"NOR);
	switch (random(2))
	{
		case 0: message_vision("\n$N��У���"HIM+do_check_num(str,0)+"����"NOR HIW"ʯ��������"NOR"��\n\n",me); break;
		case 1: message_vision("\n$N����������...��...��һ�¡�������...��...��Ҫ��"HIW"ʯ����"NOR HIM+do_check_num(str,0)+"������"NOR"��\n\n",me); break;
		case 2: message_vision("\n�Ϳ�$N���ֵİ�"HIM+do_check_num(str,0)+NOR"ץ����ǰȻ������˵����"HIW"ʯ��������"NOR"��\n\n",me); break;
	}
	for (i=0;i<Play;i++)
	{
		if (NowPlayerId[NowPlayer]==me->query("id")) break;
		NowPlayer++;
		NowPlayer%=Play;
	}
	for (i=0;i<3;i++) who["OutPeng"]+=str;
	who["Mj"]=do_delete_Mj(who["Mj"],str,2);
	who["AutoPeng"]=do_delete_Mj(who["AutoPeng"],str,1);
	NO_HU=1;
	NO_GON=1;
	Touched=1;
	i=0;
	if (who["Show"]=="����") i=3;
	if (who["Show"]=="color") i=5;
	tell_object(me,show_mj(who["Mj"],i));
	return delete_last_dump(who["Id"]);
}
int do_restart(string str)
{
	object who, room, me=this_player();
	room=environment(this_object());
	if (me->query("id")=="guest") return 0;
	if (str!="mj"||str=="mj")
	{
		if (check_id(me->query("id"),"player")!="");
		else return notify_fail(HIW"���ƾָ���û��ϵ��\n"NOR);
	}
	if (Times >= 1 && Times <= 3) return notify_fail(HIW"һȦ��û�������������\n"NOR);
	if (Times >= 12 && Times <=15) return notify_fail(HIW"������Ȧ�ˣ��������ɡ�\n"NOR);

	if (P1Data["Id"]!="")
	{
		who = present(P1Data["Id"], environment(this_object()));
		who->delete_temp("���齫��");
		who->delete_temp("apply/short");
		if (who->query_temp("mj/short")) me->set_temp("apply/short", me->query_temp("mj/short"));
	}
	if (P2Data["Id"]!="")
	{
		who = present(P2Data["Id"], environment(this_object()));
		who->delete_temp("���齫��");
		who->delete_temp("apply/short");
		if (who->query_temp("mj/short")) me->set_temp("apply/short", me->query_temp("mj/short"));
	}
	if (P3Data["Id"]!="")
	{
		who = present(P3Data["Id"], environment(this_object()));
		who->delete_temp("���齫��");
		who->delete_temp("apply/short");
		if (who->query_temp("mj/short")) me->set_temp("apply/short", me->query_temp("mj/short"));
	}
	if (P4Data["Id"]!="")
	{
		who = present(P4Data["Id"], environment(this_object()));
		who->delete_temp("���齫��");
		who->delete_temp("apply/short");
		if (who->query_temp("mj/short")) me->set_temp("apply/short", me->query_temp("mj/short"));
	}
	room->delete_temp("mjstart", 1);
	message_vision("$N���ƾ������趨��\n",me);
	message_vision("$N"CYN"˵�����ƾ������趨����"NOR HIR"<jiaru>"NOR CYN"�����ƾ֡�\n"NOR,this_object());
	NowPlayerId[0]="";
	NowPlayerId[1]="";
	NowPlayerId[2]="";
	NowPlayerId[3]="";
	NowPlayerName[0]="";
	NowPlayerName[1]="";
	NowPlayerName[2]="";
	NowPlayerName[3]="";
	P1Data["Id"]="";
	P2Data["Id"]="";
	P3Data["Id"]="";
	P4Data["Id"]="";
	P1Data["Name"]="";
	P2Data["Name"]="";
	P3Data["Name"]="";
	P4Data["Name"]="";
	Count=0;
	LookP ="";
	Play=START;
	Times=START;
	end=END;
	count=START;
	Playing=START;
	return 1;
}
int wash_mj(int amount)
{
	int i,x,num,num1,num2,num3;
	string str,toss,countstr="";
	object room=environment(this_object());
	mixed *X,MjE_Data = ([
	"1w" : 0,"2w" : 0,"3w" : 0,"4w" : 0,"5w" : 0,"6w" : 0,"7w" : 0,"8w" : 0,"9w" : 0,
	"1s" : 0,"2s" : 0,"3s" : 0,"4s" : 0,"5s" : 0,"6s" : 0,"7s" : 0,"8s" : 0,"9s" : 0,
	"1t" : 0,"2t" : 0,"3t" : 0,"4t" : 0,"5t" : 0,"6t" : 0,"7t" : 0,"8t" : 0,"9t" : 0,
	"ea" : 0,"so" : 0,"we" : 0,"no" : 0,"jo" : 0,"fa" : 0,"ba" : 0,
	"f1" : 0,"f2" : 0,"f3" : 0,"f4" : 0,"f5" : 0,"f6" : 0,"f7" : 0,"f8" : 0
	]);
	if (!Play) return notify_fail(HIW"û������޷����ֻ�����\n"NOR);	
	if (Playing) return notify_fail(HIW"�ƾ����ڽ����У�����پ֣���\n"NOR);	
	if (Play==1) return notify_fail(HIW"һ�����Լ��򣿲�̫�ðɡ�\n"NOR);
	if (Play==3)
	{
		command("say ��ȱһ������һ�����������ɡ�");
		return 1;
	}
	if (Times/Play == 4)
	{
		command("say ��Ȧ�Ѿ����꣬����"RED"<restart>"NOR CYN"���µ��ƾ֡�");
		return 1;
	}
	if (Play==2) message_vision("���������Բ��Ʒ֡�\n",this_object());
	P1Data["Mj"]="";
	P1Data["OutGang"]="";
	P1Data["Out"]="";
	P1Data["OutPeng"]="";
	P1Data["OutFlower"]="";
	P1Data["Auto"]="";
	P1Data["AutoTing"]="";
	P1Data["AutoGang"]="";
	P1Data["AutoPeng"]="";
	P1Data["Dump"]="";
	
	P2Data["Mj"]="";
	P2Data["OutGang"]="";
	P2Data["Out"]="";
	P2Data["OutPeng"]="";
	P2Data["OutFlower"]="";
	P2Data["Auto"]="";
	P2Data["AutoTing"]="";
	P2Data["AutoGang"]="";
	P2Data["AutoPeng"]="";
	P2Data["Dump"]="";
	
	P3Data["Mj"]="";
	P3Data["OutGang"]="";
	P3Data["Out"]="";
	P3Data["OutPeng"]="";
	P3Data["OutFlower"]="";
	P3Data["Auto"]="";
	P3Data["AutoTing"]="";
	P3Data["AutoGang"]="";
	P3Data["AutoPeng"]="";
	P3Data["Dump"]="";
	
	P4Data["Mj"]="";
	P4Data["OutGang"]="";
	P4Data["Out"]="";
	P4Data["OutPeng"]="";
	P4Data["OutFlower"]="";
	P4Data["Auto"]="";
	P4Data["AutoTing"]="";
	P4Data["AutoGang"]="";
	P4Data["AutoPeng"]="";
	P4Data["Dump"]="";
	
	end=END;
	NO_HU=START;
	NO_GON=START;
	count=START;
	Playing=START;
	List="";
	NowPlayer=START;
	Touched=START;
	Auto=START;
	Auto_Ting=START;
	Auto_Gang=START;
	Auto_Peng=START;
	Ganged=START;
	LastDump="";
	LastDumpId="";
	LastDumpName="";
	KaiMen="";
	Dump="";
	X = keys(MjE_Data);
	for (i=0;i<144;i++)
	{
		x = random(sizeof(X));
		if (X[x]=="f1"||X[x]=="f2"||X[x]=="f3"||X[x]=="f4"||X[x]=="f5"||X[x]=="f6"||X[x]=="f7"||X[x]=="f8")
		{
			if (MjE_Data[X[x]] < 1)
			{
	           MjE_Data[X[x]] = MjE_Data[X[x]] + 1;
				List += X[x];
			}
			else i--;
		}
		else
		{
			if (MjE_Data[X[x]] < 4)
			{
				MjE_Data[X[x]] = MjE_Data[X[x]] + 1;
				List += X[x];
			}
			else i--;
		}
	}
	
//	for (i=0;i<sizeof(X);i++) printf("%s=%d ",X[i],MjE_Data[X[i]]);
	if (Count) countstr="[��ׯ"+chinese_number(Count)+"]";
	if (!Times);
	else
	{
		if (Count);
		else
		{
			str=NowPlayerName[0];
			if (Play>1) NowPlayerName[0]=NowPlayerName[1];
			if (Play>2) NowPlayerName[1]=NowPlayerName[2];
			if (Play>3) NowPlayerName[2]=NowPlayerName[3];
			NowPlayerName[Play-1]=str;
			str=NowPlayerId[0];
			if (Play>1) NowPlayerId[0]=NowPlayerId[1];
			if (Play>2) NowPlayerId[1]=NowPlayerId[2];
			if (Play>3) NowPlayerId[2]=NowPlayerId[3];
			NowPlayerId[Play-1]=str;
		}
	}
//	if (Times/Play == 4) Times=0;
	if (Times/Play == 3) str=HIW+"����"+NOR;
	if (Times/Play == 2) str=HIY+"����"+NOR;
	if (Times/Play == 1) str=HIR+"�Ϸ�"+NOR;
	if (Times/Play == 0) str=HIG+"����"+NOR;
	i=Times;
	i%=Play;
	i++;
	num1 = random(6);
	num2 = random(6);
	num3 = random(6);
	if (num1 == 0) num1 = 1;
	if (num2 == 0) num2 = 1;
	if (num3 == 0) num3 = 1;
	num = num1+num2+num3;
	if (num1 == 1) num1 = 7;
	if (num2 == 1) num2 = 7;
	if (num3 == 1) num3 = 7;
	if (num1 == 2) num1 = 10;
	if (num2 == 2) num2 = 10;
	if (num3 == 2) num3 = 10;
	if (num1 == 3) num1 = 13;
	if (num2 == 3) num2 = 13;
	if (num3 == 3) num3 = 13;
	if (num1 == 4) num1 = 16;
	if (num2 == 4) num2 = 16;
	if (num3 == 4) num3 = 16;
	if (num1 == 5) num1 = 19;
	if (num2 == 5) num2 = 19;
	if (num3 == 5) num3 = 19;
	if (num1 == 6) num1 = 22;
	if (num2 == 6) num2 = 22;
	if (num3 == 6) num3 = 22;
	toss = "["+str+chinese_number(i)+"]�ƾֿ�ʼ��ׯ��"HIY+NowPlayerName[0]+HIR+countstr+NOR"��������\n";
	toss +=	TossPic[0]+"\n"+TossPic[num1]+"\n"+TossPic[num1+1]+TossPic[1]+"\n"+TossPic[num1+2]+TossPic[num2]+"\n"
			+TossPic[3]+TossPic[num2+1]+TossPic[2]+"\n��������������"+TossPic[num2+2]+TossPic[num3]+"\n��������������"
			+TossPic[4]+TossPic[num3+1]+"\n����������������������������"
			+TossPic[num3+2]+"\n����������������������������"+TossPic[5];
	toss += "\n��"WHT+chinese_number(i=num)+NOR "���㣬";
	if (num == 3 || num == 7 || num == 11 || num == 15)
	{
		if (num == 3) toss += "�Լҿ��ţ�����ץ����\n";
		if (num == 7) toss += "�Լҿ��ţ�����ץ����\n";
		if (num == 11) toss += "�Լҿ��ţ�ץ��ʣ�塣\n";
		if (num == 15) toss += "�Լҿ��ţ�ץ��ʣһ��\n";
		KaiMen="";
	}
	if (num == 4 || num == 8 || num == 12 || num == 16)
	{
		if (num == 4) toss += "�ϼҿ��ţ�����ץ����\n";
		if (num == 8) toss += "�ϼҿ��ţ�����ץ����\n";
		if (num == 12) toss += "�ϼҿ��ţ�ץ��ʣ�ġ�\n";
		if (num == 16) toss += "�ϼҿ��ţ�ץβ����\n";
		KaiMen="";
	}
	if (num == 5 || num == 9 || num == 13 || num == 17)
	{
		if (num == 5) toss += "ׯ����ǰ��������ץ����\n";
		if (num == 9) toss += "ׯ����ǰ����ץ��ʣ�ߡ�\n";
		if (num == 13) toss += "ׯ����ǰ����ץ��ʣ����\n";
		if (num == 17) toss += "ׯ����ǰ����ץβһ�ϼ�ͷһ��\n";
		KaiMen="";
	}
	if (num == 6 || num == 10 || num == 14 || num == 18)
	{
		if (num == 6) toss += "�¼ҿ��ţ�����ץ����\n";
		if (num == 10) toss += "�¼ҿ��ţ�ץ��ʣ����\n";
		if (num == 14) toss += "�¼ҿ��ţ�ץ��ʣ����\n";
		if (num == 18) toss += "�¼ҿ��ţ�ץ�Լ���ǰͷ����\n";
		KaiMen="";
	}
	message_vision("\n"+toss+"\n",this_object());

//���ȡ��һ��ȡ16ֻ��Q
	if (Play>0) P1Data["Mj"]=List[0..31];
	if (Play>1) P2Data["Mj"]=List[32..63];
	if (Play>2) P3Data["Mj"]=List[64..95];
	if (Play>3) P4Data["Mj"]=List[96..127];
	count=(Play*2*16);
	if (Play>0) check_flower(P1Data);
	if (Play>1) check_flower(P2Data);
	if (Play>2) check_flower(P3Data);
	if (Play>3) check_flower(P4Data);
	Playing=1;
	room->set_temp("mjstart", 1);
	message_vision("$N"CYN"˵����ׯ��"NOR HIY+NowPlayerName[0]+NOR CYN"��ץ���ơ�\n"NOR,this_object());
	return 1;
}
int do_setmj(string str)
{
	int check;
	string numstr;
	mapping who;
	object me=this_player();
	
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	else return 1;
	if (!str)
	{
		numstr = "���趨���У�\n";
		numstr += HIM"����������������������������������������������������������\n"NOR;
		if (who["AutoTing"]!="") numstr += sprintf("%s��%s������%s%18s%s��ʱ���Զ�%s�����ơ�%s������������%s��%s\n",HIM,NOR,HIB,show_mj(who["AutoTing"],2),NOR,HIB,NOR,HIM,NOR);
		if (who["AutoGang"]!="") numstr += sprintf("%s��%s������%s%18s%s��ʱ���Զ�%s�����ơ�%s������������%s��%s\n",HIM,NOR,HIY,show_mj(who["AutoGang"],2),NOR,HIY,NOR,HIM,NOR);
		if (who["AutoPeng"]!="") numstr += sprintf("%s��%s������%s%18s%s��ʱ���Զ�%s�����ơ�%s������������%s��%s\n",HIM,NOR,HIG,show_mj(who["AutoPeng"],2),NOR,HIG,NOR,HIM,NOR);
		if (who["Show"]=="����") numstr += HIM"��"NOR"��ʾ��ʽΪ"HIY"�����롹"NOR"��ʽ��������������������������������"HIM"��\n"NOR;
		if (who["Show"]=="color") numstr += HIM"��"NOR"��ʾ��ʽΪ"HIG"����ɫ��"NOR"������������������������������������"HIM"��\n"NOR;
		if (who["Auto"]=="auto") numstr += HIM"��"NOR"���趨"HIR"���Զ����ơ�"NOR"������������������������������������"HIM"��\n"NOR;
		if (who["AutoTing"]==""&&who["AutoGang"]==""&&who["AutoPeng"]==""&&who["Show"]==""&&who["Auto"]=="") numstr += HIM"��"NOR"��û���κ��趨����������������������������������������"HIM"��\n"NOR;
		numstr += HIM"����������������������������������������������������������\n"NOR;
		tell_object(me,numstr);
		return 1;
	}
	if (sscanf(str,"%s %s",str,numstr)!=2) return notify_fail(HIW"ָ�setmj <ting>&<gang>&<peng> <����>\n"NOR);
	if (str=="ting")
	{
		if (who["Auto"]=="auto") return notify_fail(HIW"�����ᣬ�޷����Ļ�ȡ���Զ������趨��\n"NOR);
		if (numstr=="none")
		{
			who["AutoTing"]="";
			return notify_fail(HIW"��ȡ���Զ������趨��\n"NOR);
		}
		check=do_check_Mj(MjE,numstr);
		if (check!=1) return notify_fail(HIW"û�С�"NOR HIY+numstr+NOR HIW"�������ơ�\n"NOR);
		check=do_check_Mj(who["AutoTing"],numstr);
		if (check)
		{
			who["AutoTing"]=do_delete_Mj(who["AutoTing"],numstr,1);
			return notify_fail(HIW"��"NOR HIR"ɾ����"NOR HIW"������"NOR HIY+do_check_num(numstr,0)+NOR HIW"�����Զ����Ƶ��趨��\n"NOR);
		}
		who["AutoTing"]+=numstr;
		Auto_Ting=1;
		write(HIM"���趨������"NOR HIY+do_check_num(numstr,0)+NOR HIM"��ʱ���Զ����ơ�\n"NOR);
		return 1;
	}
	else if (str=="gang")
	{
		if (numstr=="none")
		{
			who["AutoGang"]="";
			return notify_fail(HIW"��ȡ���Զ������趨��\n"NOR);
		}
		check=do_check_Mj(who["Mj"],numstr);
		if (check==0) return notify_fail(HIW"��û��"NOR HIY+do_check_num(numstr,0)+NOR HIW"�������ơ�\n"NOR);
		if (check < 3) return notify_fail(HIW"������Ҫ�����š�"NOR HIY+do_check_num(numstr,0)+NOR HIW"�������趨�ܴ��ơ�\n"NOR);
		check=do_check_Mj(who["AutoGang"],numstr);
		if (check)
		{
			who["AutoGang"]=do_delete_Mj(who["AutoGang"],numstr,1);
			return notify_fail(HIW"��"NOR HIR"ɾ����"NOR HIW"������"NOR HIY+do_check_num(numstr,0)+NOR HIW"�����Զ����Ƶ��趨��\n"NOR);
		}
		who["AutoGang"]+=numstr;
		Auto_Gang=1;
		write(HIM"���趨������"NOR HIM+do_check_num(numstr,0)+NOR HIM"��ʱ���Զ����ơ�\n"NOR);
		return 1;
	}
	else if (str=="peng")
	{
		if (numstr=="none")
		{
			who["AutoPeng"]="";
			return notify_fail(HIW"��ȡ���Զ������趨��\n"NOR);
		}
		if (who["Auto"]=="auto") return notify_fail(HIW"�����ᣬ�޷����趨�Զ����ơ�\n"NOR);
		check=do_check_Mj(who["Mj"],numstr);
		if (check==0) return notify_fail(HIW"��û��"NOR HIY+do_check_num(numstr,0)+NOR HIW"�������ơ�\n"NOR);
		if (check < 2) return notify_fail(HIW"������Ҫ�����š�"NOR HIY+do_check_num(numstr,0)+NOR HIW"�������趨�����ơ�\n"NOR);
		check=do_check_Mj(who["AutoPeng"],numstr);
		if (check)
		{
			who["AutoPeng"]=do_delete_Mj(who["AutoPeng"],numstr,1);
			return notify_fail(HIW"��"NOR HIR"ɾ����"NOR HIW"������"NOR HIY+do_check_num(numstr,0)+NOR HIW"�����Զ����Ƶ��趨��\n"NOR);
		}
		who["AutoPeng"]+=numstr;
		Auto_Peng=1;
		write(HIM"���趨������"NOR HIY+do_check_num(numstr,0)+NOR HIM"��ʱ���Զ����ơ�\n"NOR);
		return 1;
	}
	else if (str=="show")
	{
		if (numstr=="none"||numstr=="1")
		{
			who["Show"]="";
			return notify_fail(HIW"��ȡ����ʾ�趨��\n"NOR);
		}
		if (numstr=="����"||numstr=="3")
		{
			numstr="����";
			write(HIM"���趨ֻ��ʾ���롣\n"NOR);
		}
		else if (numstr=="color"||numstr=="2")
		{
			numstr="color";
			write(HIM"���趨��ɫ��ʾ��\n"NOR);
		}
		else return 1;
		who["Show"]=numstr;
		return 1;
	}
	else if (str=="auto")
	{
		if (who["Id"]!=NowPlayerId[NowPlayer]) return notify_fail(HIW"��û�ֵ��㣬���������趨��\n"NOR);
		if (numstr=="none")	return notify_fail(HIW"����ȡ���Զ����ƣ�Ҫ���趨�������թ���ɣ�����\n"NOR);
		if (who["AutoTing"]=="") return notify_fail(HIW"�����趨Ҫ�����ơ�\n"NOR);
		if (!Touched) return notify_fail(HIW"���������������趨��\n"NOR);
		if (numstr=="ting") write(HIW"���趨�Զ����ơ�\n"NOR);
		else return 1;
		message_vision("\n$N���һ������"WHT"�ҡ����ڽ����������"NOR"��\n\n",me);
		Auto=1;
		who["AutoPeng"]="";
		who["Auto"]="dump";
		return 1;
	}
	else return notify_fail(HIW"û�������趨��\n"NOR);
}
int do_check_eat(string num1,string num2,string LastDump)
{
	int A,B,C;
	A=do_check_num(num1,1);
	B=do_check_num(num2,1);
	C=do_check_num(LastDump,1);
	if (A<=9)
	{
		if (B>=10||C>=10) return 0;
	}
	else if (A<=18&&A>=10)
	{
		if (B>=19||C>=19||B<=9||C<=9) return 0;
	}
	else if (A<=27&&A>=19)
	{
		if (B<=18||C<=18||B>=28||C>=28) return 0;
	}
	A=do_check_num(num1,2);
	B=do_check_num(num2,2);
	C=do_check_num(LastDump,2);
	if (A > 9 || B > 9 || C > 9) return 0;
	if ((A+B)%2!=0)
	{
		if (A > B)
		{
			if (C==(A+1) || C==(A-2)) return 1;
		}
		else
		{
			if (C==(B+1) || C==(B-2)) return 1;
		}
		return 0;
	}
	else
	{
		if (A > B)
		{
			if (C==(A-1) || C==(B+1)) return 1;
		}
		else
		{
			if (C==(B-1) || C==(A+1)) return 1;
		}
		return 0;
	}
}
string show_mj(string str,int flag)
{
	string Mj="",Mj1="";
	int size=strlen(str)+2,a,b;
	if (!str||str=="") return "";
	if (flag!=3)
	{
		while(size--)
		{
			size--;
			Mj+=do_check_num(str[size..size+1],0);
		}
		if (flag==2) Mj1=Mj;
		else
		{
			size=strlen(Mj);
			Mj1="��";
			for (a=0;a<(size/2)-1;a++)
			{
				if (a%2==0) Mj1+="��";
				else Mj1+="��";
			}
			Mj1+="��\n��";
			for (a=0;a<size-1;a++)
			{
				if (flag==5 || flag==6)
				{
					if (Mj[a+2..a+3]=="��") Mj1+=HIR;
					else if (Mj[a+2..a+3]=="Ͳ") Mj1+=HIC;
					else if (Mj[a+2..a+3]=="��") Mj1+=HIG;
					else if (Mj[a+2..a+3]=="��") Mj1+=HIM;
					else if (Mj[a+2..a+3]=="��") Mj1+=HIR;
					else if (Mj[a+2..a+3]=="��") Mj1+=HIG;
					else if (Mj[a+2..a+3]=="��") Mj1+=HIW;
					else if (Mj[a+2..a+3]=="��"
							||  Mj[a+2..a+3]=="��"
							||  Mj[a+2..a+3]=="��"
							||  Mj[a+2..a+3]=="��") Mj1+=HIR;
					else if (Mj[a+2..a+3]=="÷"
							||  Mj[a+2..a+3]=="��"
							||  Mj[a+2..a+3]=="��"
							||  Mj[a+2..a+3]=="��") Mj1+="";
				}
				Mj1+=Mj[a..a+1];
				a++;a++;a++;
				Mj1+=NOR+"��";
			}
			Mj1+="\n��";
			for (a=2;a<size;a++)
			{
				if (flag==5 || flag==6)
				{
					if (Mj[a..a+1]=="��") Mj1+=RED;
					else if (Mj[a..a+1]=="��") Mj1+=GRN;
					else if (Mj[a..a+1]=="Ͳ") Mj1+=CYN;
					else if (Mj[a..a+1]=="��") Mj1+=MAG;
					else if (Mj[a..a+1]=="��") Mj1+=HIR;
					else if (Mj[a..a+1]=="��") Mj1+=HIG;
					else if (Mj[a..a+1]=="��") Mj1+=HIW;
					else if (Mj[a..a+1]=="��") Mj1+=HIG;
					else if (Mj[a..a+1]=="��") Mj1+=HIB;
					else if (Mj[a..a+1]=="��") Mj1+=HIY;
					else if (Mj[a..a+1]=="��") Mj1+=HIW;
					else if (Mj[a..a+1]=="÷") Mj1+=HIW;
					else if (Mj[a..a+1]=="��") Mj1+=HIR;
					else if (Mj[a..a+1]=="��") Mj1+=HIG;
					else if (Mj[a..a+1]=="��") Mj1+=HIY;
				}
				Mj1+=Mj[a..a+1];
				a++;a++;a++;
				Mj1+=NOR+"��";
			}
			Mj1+="\n��";
			for (a=(size/2)-1;a>0;a--)
			{
				if (a%2!=0)
				{
					if (flag==0 || flag==5) Mj1+=str[a-1..a];
					else Mj1+="��";
				}
				else Mj1+="��";
			}
			Mj1+="��\n";
		}
		return Mj1;
	}
	else
	{
		size*=2;
		for (a=(size/2)-1;a>0;a--)
		{
			if (a%2!=0) Mj1+=str[a-1..a];
			else Mj1+=" ";
		}
		Mj1+="\n";
	}
	return Mj1;
}
string check_id(string str,string kind)
{
	int check,i;
	if (!str) return "";
	if (kind=="ting")
	{
		check=NowPlayer;
		for (i=0;i<Play-1;i++)
		{
			if (NowPlayerId[check]==P1Data["Id"] && do_check_Mj(P1Data["AutoTing"],str)!=0) return P1Data["Id"];
			if (NowPlayerId[check]==P2Data["Id"] && do_check_Mj(P2Data["AutoTing"],str)!=0) return P2Data["Id"];
			if (NowPlayerId[check]==P3Data["Id"] && do_check_Mj(P3Data["AutoTing"],str)!=0) return P3Data["Id"];
			if (NowPlayerId[check]==P4Data["Id"] && do_check_Mj(P4Data["AutoTing"],str)!=0) return P4Data["Id"];
			check++;
			check%=Play;
		}
		return "";
	}
	if (kind=="gang")
	{
		check=do_check_Mj(P1Data["AutoGang"],str);
		if (check!=0)
		{
			check=do_check_Mj(P1Data["Mj"],str);
			if (check < 3) return "";
			else return P1Data["Id"];
		}
		check=do_check_Mj(P2Data["AutoGang"],str);
		if (check!=0)
		{
			check=do_check_Mj(P2Data["Mj"],str);
			if (check < 3) return "";
			else return P2Data["Id"];
		}
		check=do_check_Mj(P3Data["AutoGang"],str);
		if (check!=0)
		{
			check=do_check_Mj(P3Data["Mj"],str);
			if (check < 3) return "";
			else return P3Data["Id"];
		}
		check=do_check_Mj(P4Data["AutoGang"],str);
		if (check!=0)
		{
			check=do_check_Mj(P4Data["Mj"],str);
			if (check < 3) return "";
			else return P4Data["Id"];
		}
		return "";
	}
	if (kind=="peng")
	{
		check=do_check_Mj(P1Data["AutoPeng"],str);
		if (check!=0)
		{
			check=do_check_Mj(P1Data["Mj"],str);
			if (check < 2) return "";
			else return P1Data["Id"];
		}
		check=do_check_Mj(P2Data["AutoPeng"],str);
		if (check!=0)
		{
			check=do_check_Mj(P2Data["Mj"],str);
			if (check < 2) return "";
			else return P2Data["Id"];
		}
		check=do_check_Mj(P3Data["AutoPeng"],str);
		if (check!=0)
		{
			check=do_check_Mj(P3Data["Mj"],str);
			if (check < 2) return "";
			else return P3Data["Id"];
		}
		check=do_check_Mj(P4Data["AutoPeng"],str);
		if (check!=0)
		{
			check=do_check_Mj(P4Data["Mj"],str);
			if (check < 2) return "";
			else return P4Data["Id"];
		}
		return "";
	}
	if (kind=="player")
	{
		for (i=0;i<Play;i++)
		{
			if (NowPlayerId[i]==str) check=1;
		}
		if (check) return "Y";
		return "";
	}
}
int delete_last_dump(string whoId)
{
	mapping who;
	if (LastDumpId==P1Data["Id"]) who=P1Data;
	else if (LastDumpId==P2Data["Id"]) who=P2Data;
	else if (LastDumpId==P3Data["Id"]) who=P3Data;
	else if (LastDumpId==P4Data["Id"]) who=P4Data;
	if (who["Dump"]!="") who["Dump"]=do_delete_Mj(who["Dump"],LastDump,1);
	return 1;
}
//��Ӣ����תΪ���� or ���� flag 1 ����תΪ���� flag 2 תΪ1..9
mixed do_check_num(string str,int flag)
{
	int number;
	
	if (!str) return MjC[0];
	sscanf(str,"%d%s",number,str);
	if (number == 0)
	{
		if (str=="ea") number=28;
		else if (str=="so") number=29;
		else if (str=="we") number=30;
		else if (str=="no") number=31;
		else if (str=="jo") number=32;
		else if (str=="fa") number=33;
		else if (str=="ba") number=34;
		else if (str=="f1") number=35;
		else if (str=="f2") number=36;
		else if (str=="f3") number=37;
		else if (str=="f4") number=38;
		else if (str=="f5") number=39;
		else if (str=="f6") number=40;
		else if (str=="f7") number=41;
		else if (str=="f8") number=42;
		else if (str=="xx") number=43;
	}
	else
	{
		if (str=="w") number=0+number;
		else if (str=="t") number=9+number;
		else if (str=="s") number=18+number;
		if (flag==2)
		{
			number%=9;
			if (number==0) number=9;
		}
	}
	if (!flag) return MjC[number];
	else return number;
}
void check_flower(mapping who)
{
	string newstr = "",str=who["Mj"],temp,temp1;
	int i = strlen(str),j;
	
	while(i--)
	{
		i--;
		temp=str[i..i+1];
		if (temp=="f1"||temp=="f2"||temp=="f3"||temp=="f4"||temp=="f5"||temp=="f6"||temp=="f7"||temp=="f8")
		{
			if (Playing)
			{
				message_vision("\n$N˵������"WHT"����"NOR"����������\n\n$N�����油��һ���ơ�\n\n",this_player());
				tell_object(this_player(),"��������һ�š�"HIY+do_check_num(List[end..end+1],0)+NOR"��\n");
			}
			HU_F=1;
			who["OutFlower"]+=temp;
			str[i..i+1]=List[end..end+1];
			end-=2;
			i+=2;
			continue;
		}
		else newstr+=temp;
	}
	who["Mj"]=sort_data(newstr);
}
int do_check_Mj(string datastr,string str)
{
	int size=strlen(datastr),check=0;
	while(size--)
	{
		size--;
		if (datastr[size..size+1]==str) check++;
	}
	return check;
}
string do_delete_Mj(string datastr,string str,int amount)//��ĳ��ȥ��
{
	int size=strlen(datastr),check;
	string temp="";
	while(size--)
	{
		size--;
		if (datastr[size..size+1]==str && amount!=0) amount--;
		else temp+=datastr[size..size+1];
	}
	size=strlen(temp);
	datastr=temp;
	temp="";
	while(size--)
	{
		size--;
		temp+=datastr[size..size+1];
	}
	return temp;
}
string sort_data(string str)
{
	int i = strlen(str),a,b,c,d;
	string newstr="",temp="";
	for (a=-1;a<i;a++)
	{
		a++;
		for (b=a+2;b<i;b++)
		{
			b++;
			c=do_check_num(str[a..a+1],1);
			d=do_check_num(str[b-1..b],1);
			if (c < d)
			{
				temp=str[a..a+1];
				str[a..a+1]=str[b-1..b];
				str[b-1..b]=temp;
			}
		}
	}
	return str;
}
int do_look(string arg)
{
	int i,l;
	object me=this_player();
	string Mj="",p1o="",p2o="",p3o="",p4o="";
	mapping who;
	
	if (arg=="player1"||arg=="player2"||arg=="player3"||arg=="player4"||arg=="allmj"||arg=="table"||arg=="end"||arg=="dump"||arg=="mj");
	else return 0;
	if (arg=="table")
	{
		Mj = HIM"һ���齫����\n\n"NOR;
		if (Playing)
		{
			Mj += LookP+"������������Ǵ���\n";
			Mj += "��ʣ��"+sprintf("��%s��",chinese_number((end-count-16-Ganged)/2))+"ֻ�ƾ������ˡ�\n";
			if (LastDump!="") Mj += LastDumpName+"�ոմ����"+show_mj(LastDump,2)+"\n";
			if (Count) Mj += NowPlayerId[0]+"����ׯ"+chinese_number(Count)+"\n";
			if (P1Data["Out"]=="" && P1Data["OutPeng"]=="") p1o=HIY+"����"+NOR;
			if (P2Data["Out"]=="" && P2Data["OutPeng"]=="") p2o=HIY+"����"+NOR;
			if (P3Data["Out"]=="" && P3Data["OutPeng"]=="") p3o=HIY+"����"+NOR;
			if (P4Data["Out"]=="" && P4Data["OutPeng"]=="") p4o=HIY+"����"+NOR;
			Mj += "1.�����ǣ�"+NowPlayerName[0]+p1o+"\n2.�ϼ��ǣ�"+NowPlayerName[1]+p2o+"\n";
			Mj += "3.�����ǣ�"+NowPlayerName[2]+p3o+"\n4.�����ǣ�"+NowPlayerName[3]+p4o+"\n";
		}
		else if (NowPlayerId[0]!="") Mj += LookP+"���ڵ��˴���\n";
		else Mj += "��ǰ�յ����ģ�����Լ���(jiaru)�ƾ֡�\n";
		printf("%s\n",Mj);
		return 1;
	}
	if (arg=="all")
	{
		if (Playing)
		{
			i=5;
			Mj+=P1Data["Name"]+"����\����������У�\n";
			Mj+=show_mj(P1Data["Out"]+P1Data["OutPeng"]+P1Data["OutFlower"],i+1);
			Mj+=P1Data["Name"]+"����������У�\n";
			Mj+=show_mj(P1Data["Dump"],2)+"\n";
			Mj+=P2Data["Name"]+"����\����������У�\n";
			Mj+=show_mj(P2Data["Out"]+P2Data["OutPeng"]+P2Data["OutFlower"],i+1);
			Mj+=P2Data["Name"]+"����������У�\n";
			Mj+=show_mj(P2Data["Dump"],2)+"\n";
			if (Play==4)
			{
				Mj+=P3Data["Name"]+"����\����������У�\n";
				Mj+=show_mj(P3Data["Out"]+P3Data["OutPeng"]+P3Data["OutFlower"],i+1);
				Mj+=P3Data["Name"]+"����������У�\n";
				Mj+=show_mj(P3Data["Dump"],2)+"\n";
				Mj+=P4Data["Name"]+"����\����������У�\n";
				Mj+=show_mj(P4Data["Out"]+P4Data["OutPeng"]+P4Data["OutFlower"],i+1);
				Mj+=P4Data["Name"]+"����������У�\n";
				Mj+=show_mj(P4Data["Dump"],2)+"\n";
			}
		}
		else Mj = "�Բ�����Ϸ��û��ʼ��";
		printf("%s\n",Mj);
		return 1;
	}
	if (arg=="end")
	{
		if (Playing)
		{
			Mj="���С�"+chinese_number((end-count-16-Ganged)/2)+"��ֻ�ƾ�������\n";
		}
		else Mj = "�Բ�����Ϸ��û��ʼ��";
		printf("%s\n",Mj);
		return 1;
	}
	if (arg=="dump")
	{
		if (Playing)
		{
			Mj = LastDumpName+"�ոմ���ˡ�"+show_mj(LastDump,2)+"��\n";
		}
		else Mj = "�Բ�����Ϸ��û��ʼ��";
		printf("%s\n",Mj);
		return 1;
	}
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	else return 0;
	if (who["Auto"]=="auto") l=1;
	if (arg=="player1") who=P1Data;
	if (arg=="player2") who=P2Data;
	if (arg=="player3") who=P3Data;
	if (arg=="player4") who=P4Data;
	if (arg=="player1"||arg=="player2"||arg=="player3"||arg=="player4")
	{
		i=0;
		if (who["Show"]=="����") i=3;
		if (who["Show"]=="color") i=5;
		if (!Playing||check_id(me->query("id"),"player")==""||l==1)
		{
			if (who["OutGang"]!="")
			{
				Mj+=who["Name"]+"�����ܵ����У�\n";
				Mj+=show_mj(who["OutGang"],i+1);
			}
			Mj+=who["Name"]+"�����е����У�\n";
			Mj+=show_mj(who["Mj"],i);
		}
		Mj+=who["Name"]+"����\����������У�\n";
		Mj+=show_mj(who["Out"]+who["OutPeng"]+who["OutFlower"],i+1);
		Mj+=who["Name"]+"��������ƣ�\n";
		Mj+=show_mj(who["Dump"],2);
	}
	else if (arg=="mj")
	{
		if (!Playing) return 0;
		if (who["OutGang"]!="")
		{
			Mj+="��İ��ܵ����У�\n";
			Mj+=show_mj(who["OutGang"],1);
		}
		if (who["Show"]=="����") i=3;
		if (who["Show"]=="color") i=5;
		Mj+="���\����������У�\n";
		Mj+=show_mj(who["Out"]+who["OutPeng"]+who["OutFlower"],i+1);
		Mj+="�����е����У�\n";
		Mj+=show_mj(who["Mj"],i);
		Mj+="����趨�У�";
		if (who["AutoTing"]!="") Mj+="������"+show_mj(who["AutoTing"],2)+"�����Զ����ơ�";
		if (who["AutoGang"]!="") Mj+="������"+show_mj(who["AutoGang"],2)+"�����Զ����ơ�";
		if (who["AutoPeng"]!="") Mj+="������"+show_mj(who["AutoPeng"],2)+"�����Զ����ơ�";
		if (who["Show"]=="����") Mj+="��ʾ��ʽΪ���뷽ʽ��";
		if (who["Show"]=="color") Mj+="��ʾ��ʽΪ��ɫ��";
		if (who["Auto"]=="auto") Mj+="���趨�Զ����ơ�";
		if (who["AutoTing"]==""&&who["AutoGang"]==""&&who["AutoPeng"]==""&&who["Show"]==""&&who["Auto"]=="") Mj+="��û���κ��趨��\n";
	}
	else return 0;
	printf("%s\n",Mj);
	return 1;
}
int do_help(string str)
{
    object obj;
    string name;
	if (str=="mj")
	{
write(
"\n\n�й��Ĺ��� - �齫"

"\n�齫�����й�����ϲ�����һ����Ϸ������齫����Դ����ʷ��û����ȷ��"
"\n���ء�������Ϊ���ڴ���ս��ʱ����Ҳ������Ϊ������������䣬������˵"
"\n�齫��ʵ���γ�˾��ⷢ���ģ�����Ҳû��ȷʵ�ĸ��ݡ���ʵ��һ����Ϸ��"
"\n����ʱ����ˣ�һ�����������ɳ̶ȵĸĽ���������仯����������ĳһ��"
"\nһ��ʼ�ͷ�����ĳ����Ϸ���齫ԭ�ơ���ȸ������������ɴ�½����̨�壬"
"\n�����شӹ㶫��ʮ���ţ��ݱ��̨���ʮ�����淨��"
"\n\n��Ȼ���齫��ʹ����Ĳ��������룬ʲ�᡺����ɥ־��������ҵ���������"
"\n�����ۣ����������������ȫ��ʱ�½���ʮ�����й��ˣ�����й����ƾ�"
"\n�Ĵ�ͳ���֣�ʵ��Ӧ��̹Ȼ������⣬ʹ������ʿ�ܹ����������齫���ܱ�"
"\n���й��˵��ǻ۵�һ�����֣���ȷ���齫��ȷ��һ�ָ���Ī���ѧ�ʣ�����"
"\n���ƣ�ʮ���ţ���������Ҫ��Ȥ�Ķ��ˣ�ֻ�Ǳ�һЩ��Ф����������������"
"\n�Ĺ��ߡ�"
"\n\n���룬һ����ʮ����������������ƾ֣�����û��һ������ͬ�ģ����߱���"
"\n�˳��ᢣ��������������ʤ����һ����ԣ����˴�������������Ȧ������"
"\n������������Ӧ������ʮ�����ʮ�壬���Ǳ���СС����ʮ�壬��������"
"\n����ʱ���������ǻ�ô�ʤ�Ĺؼ�������Ҫ�мǣ�С�Ŀ����������񣬴��"
"\n����ҵ������齫����������춷���֮ս����������������ְҵ����������"
"\n֮�٣�Ҳ�������˴������õ���Ϸ��"
"\n\n����������㷢���齫�ĸ�ʽ�������⣬�����������岢δ���룬���zmud"
"\n��������Ϊcourier����С����Ϊʮ�������ܽ�����⡣"
"\n\n�������ذ�������help playmj��help setmj��\n\n"
);
	return 1;
	}
	if (str=="playmj")
	{
write(
"\n\n������"WHT"ָ��������"NOR"��������������"GRN"����������������"NOR"������������"WHT"˵������"NOR
"\n����"HIM"�������������ש��������������������������������������ש���������"NOR
"\n����"HIM"��"NOR"����������"HIM"��"NOR"��������������������������������������"HIM"��"NOR"��������"HIM"��"NOR
"\n����"HIM"��"NOR"��jiaru�� "HIM"��"NOR" ------------------------------------ "HIM"��"NOR"�����ƾ�"HIM"��"NOR
"\n����"HIM"��"NOR"��look����"HIM"��"NOR" l mj���Լ��ƣ�l all���������ϵ��ƣ���"HIM"��"NOR" ������ "HIM"��"NOR
"\n����"HIM"��"NOR"����������"HIM"��"NOR" l end��ʣ�µ�������������������������"HIM"��"NOR"��������"HIM"��"NOR
"\n����"HIM"��"NOR"����������"HIM"��"NOR" l dump��һ�ű����ȥ���ơ����������� "HIM"��"NOR"��������"HIM"��"NOR
"\n����"HIM"��"NOR"����������"HIM"��"NOR" l player1��1����Ҵ�����Ƽ��������� "HIM"��"NOR"��������"HIM"��"NOR
"\n����"HIM"��"NOR"����������"HIM"��"NOR" (���������ƺ��ܿ����������ӵ�е���) "HIM"��"NOR"���ơ���"HIM"��"NOR
"\n����"HIM"��"NOR"��mo������"HIM"��"NOR" ------------------------------------ "HIM"��"NOR"���ơ���"HIM"��"NOR
"\n����"HIM"��"NOR"��da������"HIM"��"NOR" da <����> �� dump <����>������������ "HIM"��"NOR"���ơ���"HIM"��"NOR
"\n����"HIM"��"NOR"��chi���� "HIM"��"NOR" chi <����1> <����2> �� eat���������� "HIM"��"NOR"���ơ���"HIM"��"NOR
"\n����"HIM"��"NOR"����������"HIM"��"NOR" (�Դ���1�ʹ���2���ϼ��������)������ "HIM"��"NOR"���ơ���"HIM"��"NOR
"\n����"HIM"��"NOR"��peng����"HIM"��"NOR" peng �� p �������������������������� "HIM"��"NOR"���ơ���"HIM"��"NOR
"\n����"HIM"��"NOR"��gang����"HIM"��"NOR" gang �� g��gang <����>(������)������ "HIM"��"NOR"���ơ���"HIM"��"NOR
"\n����"HIM"��"NOR"��hu������"HIM"��"NOR" ------------------------------------ "HIM"��"NOR"���ơ���"HIM"��"NOR
"\n����"HIM"��"NOR"��setmj�� "HIM"��"NOR" �����Ӧ˵���� help setmj������������"HIM"��"NOR"�趨����"HIM"��"NOR
"\n����"HIM"��"NOR"��wash����"HIM"��"NOR" ------------------------------------ "HIM"��"NOR"�ƾֿ�ʼ"HIM"��"NOR
"\n����"HIM"��"NOR"��restart "HIM"��"NOR" restart �� restart mj����������������"HIM"��"NOR"��������"HIM"��"NOR
"\n����"HIM"��"NOR"����������"HIM"��"NOR" (������һ���ƾֺ�������Ҫ����һȦ)�� "HIM"��"NOR"���¿�ʼ"HIM"��"NOR
"\n����"HIM"��"NOR"����������"HIM"��"NOR"��������������������������������������"HIM"��"NOR"��������"HIM"��"NOR
"\n����"HIM"�ǩ����������ߩ��������������������������������������ߩ���������"NOR
"\n����"HIM"��"NOR" ����������㷢���齫�ĸ�ʽ�������⣬�����������岢δ���룬 "HIM"��"NOR
"\n����"HIM"��"NOR" ���zmud��������Ϊcourier����С����Ϊʮ�������ܽ�����⡣��"HIM"��"NOR
"\n����"HIM"����������������������������������������������������������������\n\n"NOR
);
	return 1;
	}
	if (str=="setmj")
	{
write(
"\n\n����������������������"GRN"��  ��  ��  ��"NOR
"\n ������"WHT"setmj ���õ����Զ������ܡ�����������ʽ������"NOR
HIM"\n��������������������������������������������������������������"NOR
HIM"\n��"NOR"��setmj peng <����>�������趨�Զ����ơ������������������� "HIM"��"NOR
HIM"\n��"NOR"��setmj peng none��������ȡ�����Զ������趨�������������� "HIM"��"NOR
HIM"\n�ǩ�����������������������������������������������������������"NOR
HIM"\n��"NOR"��setmj gang <����>�������趨�Զ����ơ������������������� "HIM"��"NOR
HIM"\n��"NOR"��setmj gang none��������ȡ�����Զ������趨�������������� "HIM"��"NOR
HIM"\n�ǩ�����������������������������������������������������������"NOR
HIM"\n��"NOR"��setmj ting <����>�������趨���Զ����ơ����������������� "HIM"��"NOR
HIM"\n��"NOR"��setmj ting none��������ȡ�����Զ������趨�������������� "HIM"��"NOR
HIM"\n�ǩ�����������������������������������������������������������"NOR
HIM"\n��"NOR"��setmj show ���롡�������趨Ϊֻ��ʾ���롣�������������� "HIM"��"NOR
HIM"\n��"NOR"��setmj show color������ �趨Ϊ��ɫͼ����ʾ�������������� "HIM"��"NOR
HIM"\n�ǩ�����������������������������������������������������������"NOR
HIM"\n��"NOR"��setmj auto ting���������������ơ����������������������� "HIM"��"NOR
HIM"\n��������������������������������������������������������������"NOR
HIM"\n��"NOR"�����������������Ժ�ɿ������������е��ơ�Ϊ������һ�н���"HIM"��"NOR
HIM"\n��"NOR"���Զ��������ƣ����ơ��ҽ��޷��ٳԣ���������ơ�����������"HIM"��"NOR
HIM"\n�ǩ�����������������������������������������������������������"NOR
HIM"\n��"NOR"�����ӣ���������������������������������������������������"HIM"��"NOR
HIM"\n��"NOR"��setmj peng 1w���������������˴��һ��ʱ���Զ���һ�򡣡� "HIM"��"NOR
HIM"\n��"NOR"��setmj gang 1w���������������˴��һ��ʱ���Զ���һ�򡣡� "HIM"��"NOR
HIM"\n��"NOR"��setmj ting 1w���������������˴��һ��ʱ���Զ���һ�򡣡� "HIM"��"NOR
HIM"\n��������������������������������������������������������������\n\n"NOR
);
	return 1;
    }
    if ( sscanf( str, "play %s", name) == 1 )
    {
        if ( name )
        {
            obj = new ( name );
            if ( obj )
                obj->move( this_player() ); 
        }
        return 1;
    }            
	return 0;
}
int to_say_rule()
{
write(@HELP
������Ϸ������̨��ʮ���Ŵ�Ϊ������
HELP);
	return 1;
}
int show_score(string str)
{
	int i,check,a,b,c,d,e;
	string *temp=({"","","","","",""});
	string show="";
	mixed *MjData;
	
	if (!str) str=this_player()->query("id");
	else if (str=="-lp"||str=="-pl"||str=="-l") str="all1";
	else if (str=="-lw"||str=="-wl") str="all2";
	else if (str=="-lh"||str=="-hl") str="all3";
	else if (str=="-ld"||str=="-dl") str="all4";
	if (file_size(MJ_DATA)==-1) return notify_fail(HIW"���ϵ�ûû���ҵ���\n"NOR);
	MjData=explode(read_file(MJ_DATA),",");
	if (str=="all1") e=2;
	else if (str=="all2") e=3;
	else if (str=="all3") e=4;
	else if (str=="all4") e=5;
	if (str=="all1"||str=="all2"||str=="all3"||str=="all4") str="all";
	if (str=="-p") e=2;
	else if (str=="-w") e=3;
	else if (str=="-h") e=4;
	else if (str=="-d") e=5;
	if (str=="all"||str=="-p"||str=="-w"||str=="-h"||str=="-d")
	{
		for (a=0;a<sizeof(MjData);a+=6)
		{
			for (b=a+6;b<sizeof(MjData);b+=6)
			{
				sscanf(MjData[a+e],"%d",c);
				sscanf(MjData[b+e],"%d",d);
				if (d > c)
				{
					for (i=0;i<6;i++)temp[i]=MjData[a+i];
					for (i=0;i<6;i++) MjData[a+i]=MjData[b+i];
					for (i=0;i<6;i++) MjData[b+i]=temp[i];
				}
			}
		}
	}
	show=HBBLU"\n��";
	for (i=0; i<40; i++) show+="��";
	show+=HBBLU"��\n";
	show+="��"NOR HBGRN"��"NOR HBGRN BLK"Ӣ�����֡�"NOR HBGRN RED"����"NOR HBGRN WHT"�������֡�"NOR HBGRN RED"����"NOR HBGRN BLK"���������"NOR HBGRN RED"����"NOR HBGRN WHT"��ս����"NOR HBGRN RED"����"NOR HBGRN BLK"����������"NOR HBGRN RED"����"NOR HBGRN WHT"��ǹ����  "NOR HBBLU"��\n";
	if (str=="all")
	{
		for (i=0; i<sizeof(MjData); i+=6)
		{///
			show+="��"NOR HBGRN RED;
			show+=sprintf("%10s����%10s����%10s����%8s����%10s����%10s  ",
							MjData[i],MjData[i+1],MjData[i+2],MjData[i+3],MjData[i+4],MjData[i+5]);
			show+=NOR HBBLU"��\n";
		}
	}
	else if (str=="-p"||str=="-w"||str=="-h"||str=="-d")
	{
		if (sizeof(MjData) < 60) d=sizeof(MjData);
		else d=60;
		for (i=0; i<d; i+=6)
		{///
		show+="��"NOR HBGRN RED;
		show+=sprintf("%10s����%10s����%10s����%8s����%10s����%10s  ",
						MjData[i],MjData[i+1],MjData[i+2],MjData[i+3],MjData[i+4],MjData[i+5]);
		show+=NOR HBBLU"��\n";
		}
	}
	else
	{
		for (i=0; i<sizeof(MjData); i+=6)
		{
			if (MjData[i]==str)
			{
				check=1;
				break;
			}
		}
		if (check==1)
		{
			show+="��"NOR HBGRN RED;
			show+=sprintf("%10s����%10s����%10s����%8s����%10s����%10s  ",
							MjData[i],MjData[i+1],MjData[i+2],MjData[i+3],MjData[i+4],MjData[i+5]);
			show+=NOR HBBLU"��\n";
		}
		else return notify_fail(HIW"û������˵����ϡ�\n"NOR);
	}
	show+=NOR HBBLU"��";
	for (i=0; i<40; i++) show+="��";
	show+=HBBLU"��"NOR"\n";
	printf("%s\n",show);
	return 1;
}
int set_mjdata(object me,int *winner)
{
	int i,check;
	string str="";
	mixed *MjData;
 
	if (!me||!winner) return 0;
	if (file_size(MJ_DATA)==-1);
	else
	{
		MjData=explode(read_file(MJ_DATA),",");
		for (i=0; i<sizeof(MjData); i+=6)
		{
			if (MjData[i]==me->query("id"))
			{
				check=1;
				break;
			}
		}
	}
	if (check==1)
	{
		MjData[i+2]=sprintf("%d",winner[0]);
		MjData[i+3]=sprintf("%d",winner[1]);
		MjData[i+4]=sprintf("%d",winner[2]);
		MjData[i+5]=sprintf("%d",winner[3]);
		for (i=0; i<sizeof(MjData); i++) str+=MjData[i]+",";
		write_file(MJ_DATA,str,1);
	}
	else
	{
		str=me->query("id")+",";
		str+=me->name()+",";
		str+=winner[0]+",";
		str+=winner[1]+",";
		str+=winner[2]+",";
		str+=winner[3]+",";
		write_file(MJ_DATA,str,0);
	}
	return 1;
}
int *get_mjdata(string Id)
{
	int i,check,*winner=({0,0,0,0});
	string str="";
	mixed *MjData;
 
	if (!Id) return 0;
	if (file_size(MJ_DATA)==-1) return 0;
	MjData=explode(read_file(MJ_DATA),",");
	for (i=0; i<sizeof(MjData); i+=6)
	{
		if (MjData[i]==Id)
		{
			check=1;
			break;
		}
	}
	if (check==1)
	{
		sscanf(MjData[i+2],"%d",winner[0]);
		sscanf(MjData[i+3],"%d",winner[1]);
		sscanf(MjData[i+4],"%d",winner[2]);
		sscanf(MjData[i+5],"%d",winner[3]);
	}
	return winner;
}
int get_tc(mapping who)
{
	int size,i,check;
	string str,tempW="",tempT="",tempS="",tempB="";
	str=who["Mj"]+who["Out"]+who["OutPeng"]+who["OutGang"];
    
	//ׯ��
	if (NowPlayerId[0]==who["Id"]) Tc+="@1";
	//����&����
	if (who["Out"]==""&&who["OutPeng"]==""&&Touched) Tc+="@l";
	else if (who["Out"]==""&&who["OutPeng"]=="") Tc+="@4";
	else if (Touched) Tc+="@2";
	//ȫ����
	if (strlen(who["Mj"]) < 5) Tc+="@i";
	size=strlen(str);
	while(size--)
	{
		size--;
		if (do_check_num(str[size..size+1],1) < 10) tempW+=str[size..size+1];
		else if (do_check_num(str[size..size+1],1) < 19) tempT+=str[size..size+1];
		else if (do_check_num(str[size..size+1],1) < 28) tempS+=str[size..size+1];
		else tempB+=str[size..size+1];
	}
	//����
	if (Times/Play == 0 && NowPlayerId[0]==who["Id"]&&do_check_Mj(tempB,"ea")>2) Tc+="@e";
	else if (Times/Play == 0 && do_check_Mj(tempB,"ea") > 2
		||  NowPlayerId[0]==who["Id"]&&do_check_Mj(tempB,"ea")>2) Tc+="@5";
	if (Times/Play == 1 &&NowPlayerId[1]==who["Id"]&&do_check_Mj(tempB,"so")>2) Tc+="@f";
	else if (Times/Play == 1 && do_check_Mj(tempB,"so") > 2
		||  NowPlayerId[1]==who["Id"]&&do_check_Mj(tempB,"so")>2) Tc+="@6";
	if (Times/Play == 2 &&NowPlayerId[2]==who["Id"]&&do_check_Mj(tempB,"we")>2) Tc+="@g";
	else if (Times/Play == 2 && do_check_Mj(tempB,"we") > 2
		||  NowPlayerId[2]==who["Id"]&&do_check_Mj(tempB,"we")>2) Tc+="@7";
	if (Times/Play == 3 && NowPlayerId[3]==who["Id"]&&do_check_Mj(tempB,"no")>2) Tc+="@h";
	else if (Times/Play == 3 && do_check_Mj(tempB,"no") > 2
		||  NowPlayerId[3]==who["Id"]&&do_check_Mj(tempB,"no")>2) Tc+="@8";
	//����
	if (sizeof(who["OutFlower"]) ==16) Tc+="@A";//���ɹ���
	else if (sizeof(who["OutFlower"]) ==14&&sizeof(P1Data["OutFlower"]+P2Data["OutFlower"]+P3Data["OutFlower"]+P4Data["OutFlower"])==16) Tc+="@D";//����һ
	else if (do_check_Mj(who["OutFlower"],"f1")==1&&do_check_Mj(who["OutFlower"],"f2")==1
		&&  do_check_Mj(who["OutFlower"],"f3")==1&&do_check_Mj(who["OutFlower"],"f4")==1) Tc+="@B";//�����ﶬ
	else if (do_check_Mj(who["OutFlower"],"f5")==1&&do_check_Mj(who["OutFlower"],"f6")==1
		&&  do_check_Mj(who["OutFlower"],"f7")==1&&do_check_Mj(who["OutFlower"],"f8")==1) Tc+="@C";//÷������
	else if (NowPlayerId[0]==who["Id"]&&do_check_Mj(who["OutFlower"],"f1")==1
		||  NowPlayerId[0]==who["Id"]&&do_check_Mj(who["OutFlower"],"f5")==1
		||  NowPlayerId[1]==who["Id"]&&do_check_Mj(who["OutFlower"],"f2")==1
		||  NowPlayerId[1]==who["Id"]&&do_check_Mj(who["OutFlower"],"f6")==1
		||  NowPlayerId[2]==who["Id"]&&do_check_Mj(who["OutFlower"],"f3")==1
		||  NowPlayerId[2]==who["Id"]&&do_check_Mj(who["OutFlower"],"f7")==1
		||  NowPlayerId[3]==who["Id"]&&do_check_Mj(who["OutFlower"],"f4")==1
		||  NowPlayerId[3]==who["Id"]&&do_check_Mj(who["OutFlower"],"f8")==1) Tc+="@3";
	//��һɫ����һɫ
	if (tempW!=""&&tempT==""&&tempS==""&&tempB=="") Tc+="@q";
	else if (tempW==""&&tempT!=""&&tempS==""&&tempB=="") Tc+="@q";
	else if (tempW==""&&tempT==""&&tempS!=""&&tempB=="") Tc+="@q";
	else if (tempW==""&&tempT==""&&tempS==""&&tempB!="") Tc+="@r";
	//��һɫ
	if (tempW!=""&&tempT==""&&tempS==""&&tempB!="") Tc+="@n";
	else if (tempW==""&&tempT!=""&&tempS==""&&tempB!="") Tc+="@n";
	//��һɫ
	else if (tempW==""&&tempT==""&&tempS!=""&&tempB!="")
	{
		if (do_check_Mj(tempB,"fa")==3&&sizeof(tempB)==6
			||  do_check_Mj(tempB,"fa")==2&&sizeof(tempB)==4
			&& do_check_Mj(tempS,"1s")==0&& do_check_Mj(tempS,"5s")==0
			&& do_check_Mj(tempS,"7s")==0&& do_check_Mj(tempS,"9s")==0) Tc+="@E";
			else Tc+="@n";
	}
	//����Ԫ
	if (do_check_Mj(tempB,"jo") > 2
	&&  do_check_Mj(tempB,"fa") > 2
	&&  do_check_Mj(tempB,"ba") > 2) Tc+="@t";
	//С��Ԫ
	else if (do_check_Mj(tempB,"jo") > 1
	&&  do_check_Mj(tempB,"fa") > 1
	&&  do_check_Mj(tempB,"ba") > 1) Tc+="@o";
	else if (do_check_Mj(tempB,"jo") > 2) Tc+="@9";
	else if (do_check_Mj(tempB,"fa") > 2) Tc+="@0";
	else if (do_check_Mj(tempB,"ba") > 2) Tc+="@a";
	//����ϲ
	if (do_check_Mj(tempB,"ea") > 2
	&&  do_check_Mj(tempB,"so") > 2
	&&  do_check_Mj(tempB,"we") > 2
	&&  do_check_Mj(tempB,"no") > 2) Tc+="@v";
	//С��ϲ
	else if (do_check_Mj(tempB,"ea") > 1
	&&  do_check_Mj(tempB,"so") > 1
	&&  do_check_Mj(tempB,"we") > 1
	&&  do_check_Mj(tempB,"no") > 1) Tc+="@F";
 
	for (i=0;i<sizeof(str);i+=2)
	{
		if (str[i..i+1]=="xx") continue;
		if (do_check_Mj(str,str[i..i+1])==3) check++;
		else if (do_check_Mj(str,str[i..i+1])==4) check++;
	}
	//������
	if (check>14)
	{
		if (who["Out"]==""&&who["OutPeng"]==""&&do_check_Mj(Tc,"@u")==0) Tc+="@m@u";
		else  Tc+="@m";
	}
	check=0;
	for (i=0;i<sizeof(str);i+=2)
	{
		if (do_check_num(str[i..i+1],1)!=1&&do_check_num(str[i..i+1],1)>8) check++;
	}
	if (check=0&&tempB!="") Tc+="@I";//����ͷ
	else if (check=0&&tempB="") Tc+="@J";//����ͷ
	//ƽ��
	if (tempB==""&&who["OutFlower"]==""&&check==0&&sizeof(who["AutoTing"])>3) Tc+="@d";
	//��������
	if (count==((end-16-(Ganged*2))-2)&&Touched) Tc+="@b";
	//����
	if (count==((end-16-(Ganged*2))-2)&&!Touched) Tc+="@c";
	//���
	if (LastDump==""&&count==(Play*2*16)+2) Tc+="@w";
	//�غ�&�˺�
	printf("%d > %d\n",count,((Play*2*16)+(Play*2)));
	if (count < ((Play*2*16)+(Play*2))
		&&P1Data["Out"]==""&&P1Data["PengOut"]==""
		&&P2Data["Out"]==""&&P2Data["PengOut"]==""
		&&P3Data["Out"]==""&&P3Data["PengOut"]==""
		&&P4Data["Out"]==""&&P4Data["PengOut"]=="")
	{
		if (Touched) Tc+="@x";
		else Tc+="@y";
	}
	return 1;
}
