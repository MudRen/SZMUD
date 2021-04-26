// By FunBoo@shenzhou
// Yiren.C ����

inherit NPC;		// This is a NPC
inherit F_VENDOR;	// Use to deal with money, I will take a look later
#include <ansi.h>

// Functions declearation:
int accept_object(object who, object what);				// Accept gold from a player
int do_setmuou(string setting);							// Get user input and setup the NPC
void Reset_Yiren();										// Reset yiren to the beginning stage
void Check_User_Input(object me);						// Check user input for setup NPC, if all needs is filled, start setup the NPC
void Set_Muou(object Obj_Muou_Owner);					// Set NPC status
void Auto_Set(object who);								// Auto set NPC if the setup time is over
void B_Not_Come();										// If A came asked, and no B present in a time
void Reset_All_Vars();									// Reset all global vars
void Muou_Fight();										// After 2 muou is set, call this function to start fight
void Start_Fight();										// Officially start the fight, call by Muou_Fight()
void Finish_Fight();									// Finisht the fight if time is over. 300 seconds (5 mins)

// Global Variables:
object Obj_Yiren;			// Store Yiren
object Obj_Player_A;		// Store Player A
object Obj_Player_B;		// Store Player B
object Obj_Muou_A;			// Store muou A
object Obj_Muou_B;			// Store muou B
int Got_Money;				// Get how many money from player to start the game
string s_Muou_Menpai;		// Stone muou's menpai
int n_Muou_Age;				// Store muou's age
int n_Muou_Skills_Level;	// Store muou's skills level
int	n_Muou_Xinfa_Level;		// Store muou's xinfa level
int n_Muou_Str;				// Store muou's Str
int n_Muou_Int;				// Store muou's Int
int n_Muou_Con;				// Store muou's Con
int n_Muou_Dex;				// Store muou's Dex
int n_Muou_Deathcount;		// Store muou's deathcount
int n_Muou_Pxj;				// Store if muou can use pxj

// Basic setup for a NPC
void create()
{
	set_name("����", ({"yiren", "yi ren"}));
	set("gender", "����");
	set("age", 60);
	set("long", "����һ��ľż�����ˣ�����ľż��Ϊ����\n"+"��������ʮ���ƽ����ͻ������Լ�����ƺͲ���ľż��\n");
	set("combat_exp", 9000);
	set("shen_type", 1);			// What is the value for this?
	set("attitude", "friendly");
	set("no_refresh", 1);

	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("max_neili", 1000);

	set_skill("strike", 30);
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);

	set_temp("fighting", 0);
	setup();
	carry_object("/d/city/obj/cloth")->wear();

	Obj_Yiren=this_object();
	Got_Money = 10000;					    // 1 gold
	n_Muou_Pxj = 0;							// Muou cannot use pxj by default
}

// Add new action to setup the muou age, exp, skills etc.
int init()
{
	object *obs, me=this_object();

	add_action("do_setmuou", "setmuou");

	// Destruct the old one if there is any
	obs = filter_array(children("/d/city/npc/yiren"), (: clonep :));
    if (sizeof(obs) > 1)
	{
		message("vision", me->name(1)+"����ææ���뿪��.\n", environment(me), me);
		destruct(me);
		return 1;
    }
}

// Use to accept gold from a player
int accept_object(object who, object what)
{
	if(what->query("money_id") && what->value() >= Got_Money)
	{
		// Got money from 2 players, fight is ready to start, not goint to receive money
		if(Obj_Yiren->query_temp("Both_Paid"))
		{
			// If plyaer A & B still there
			if(objectp(Obj_Player_A) && objectp(Obj_Player_B))
			{
				command("say "+Obj_Player_A->query("name")+"��"+Obj_Player_B->query("name")+"������ľżϷ�����һ�¡�\n");
			}
			// If either one player is missing
			else
			{
				// If muou A & B still there
				if(objectp(Obj_Muou_A) && objectp(Obj_Muou_B) && interactive(Obj_Muou_A) && interactive(Obj_Muou_B))
				{
					Obj_Muou_A->quit(Obj_Muou_A);
					Obj_Muou_B->quit(Obj_Muou_B);
				}
				// Reset
				Reset_Yiren();
				command ("say �ף���ô�˲����ˣ����Ǹ��ҿ���Ц�ɣ���һ��Ҫ����ϡ�");
			}
			// Not accept money
			return 0;
		}

		// If A is paid and A's setup is not finish yet
		if (Obj_Yiren->query_temp("A_Paid_Gold") && !Obj_Yiren->query_temp("A_Finish_Setup"))
		{
			tell_object(who, "���˸����㣺"+Obj_Player_A->query("name")+"�������ľż�����һ�¡�\n");
			return 0;
		}

		// If B is paid and B's setup is not finish yet
		if(Obj_Yiren->query_temp("B_Paid_Gold") && !Obj_Yiren->query_temp("B_Finish_Setup"))
		{
			tell_object(who, "���˸����㣺"+Obj_Player_B->query("name")+"�������ľż�����һ�¡�\n");
			return 0;
		}

		// If the money giver is PlayerA or Player B, and their setup is already finish:
		if(who == Obj_Yiren->query_temp("Player_A") || who == Obj_Yiren->query_temp("Player_B"))
		{
			tell_object(who, "���Ѿ���Ǯ�ˣ�����ʲôǮ��\n");
			return 0;
		}

		// If no one in the game
		if(!Obj_Yiren->query_temp("A_Paid_Gold"))
		{
			Obj_Yiren->set_temp("A_Paid_Gold", who->query("id"));	// Give yiren a var as player A's ID
			Obj_Yiren->set_temp("A_Started_Setup", 1);				// Player A is started to setup the NPC
			Obj_Player_A = who;										// Set A object
			Obj_Yiren->set_temp("Player_A", Obj_Player_A);			// Set player A to yiren
			Obj_Player_A->set_temp("n_Muou_Cannot_Leave", 1);			// Do not allow Player A leave
			command("nod");
			command("say ����Կ�ʼ������Լ���ľż�ˡ�\n");
			// After flags are set, main handler change to setmuou function, 
			// now user need to use setmuou to setup the NPC

			remove_call_out("Auto_Set");							// Call out auto set muou if time is over
			call_out("Auto_Set", 120, Obj_Player_A);

			return 1;
		}
		
		// If player A is the one who did setup, and he is finished his setup, now B come, make sure B is not A
		if((Obj_Yiren->query_temp("A_Paid_Gold")) && (Obj_Yiren->query_temp("A_Finish_Setup")) && (who != Obj_Yiren->query_temp("Player_A")))
		{
			remove_call_out("B_Not_Come");							// B came, remove the call out
			Obj_Yiren->set_temp("B_Paid_Gold", who->query("id"));	// Give yiren a var as player B's ID
			Obj_Yiren->set_temp("B_Started_Setup", 1);				// Player B is started to setup the NPC
			Obj_Player_B = who;										// Set B object
			Obj_Yiren->set_temp("Player_B", Obj_Player_B);			// Set player B to yiren
			Obj_Player_B->set_temp("n_Muou_Cannot_Leave", 1);			// Do not allow Player B leave
			command("nod");
			command("say ����Կ�ʼ������Լ���ľż�ˡ�\n");

			// After flags are set, main handler change to setmuou function, 
			// now user need to use setmuou to setup the NPC
			remove_call_out("Auto_Set");							// Call out auto set muou if time is over
			call_out("Auto_Set", 120, Obj_Player_B);

			return 1;
		}
		return 0;
	}

	if(what->query("money_id") && what->value() < Got_Money)
	{
		command("say ��Դ���������ƣ����߲��ܣ�");
		return 1;
	}
	return 0;
}

int do_setmuou(string setting) // Get user input and setup the NPC
{
	object me, Obj_Who_Is_Doing_Setup;
	int n_Value;
	string s_Name, s_Value;

	me = this_player();

	if (!setting)
	{
		return notify_fail("��Ҫ���ʲô��\n");
	}

	// If player A is the one who should do setup, and he is not finish his setup yet OR
	// If player B is the one who should do setup, and he is not finish his setup yet
	if ((Obj_Yiren->query_temp("A_Paid_Gold") && Obj_Yiren->query_temp("A_Started_Setup") && !Obj_Yiren->query_temp("A_Finish_Setup") && me==Obj_Player_A) || (Obj_Yiren->query_temp("B_Paid_Gold") && Obj_Yiren->query_temp("B_Started_Setup") && !Obj_Yiren->query_temp("B_Finish_Setup") && me==Obj_Player_B));
	else // If not
	{
		tell_object(me, "�Բ��������ڲ������ľż��\n");
		return 1;
	}

	// If the input is correct
	if(sscanf(setting, "%s %d", s_Name, n_Value)==2 || sscanf(setting, "%s %s", s_Name, s_Value)==2);
	else // If input is incorrect
	{
		return notify_fail("���������������\n");
		return 1;
	}
	
	switch(s_Name)
	{
	case "age":
		if (n_Value>=20 && n_Value<=200)
		{
			n_Muou_Age = n_Value;
			command("say ľż�����Ϊ��"+n_Value+"�ꡣ\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "skill":
		if (n_Value>=1 && n_Value<=800)
		{
			n_Muou_Skills_Level = n_Value;
			command("say ľż�ļ��ܵȼ�Ϊ��"+n_Value+"��\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "xinfa":
		if (n_Value>=1 && n_Value<=800)
		{
			n_Muou_Xinfa_Level = n_Value;
			command("say ľż���ķ��ȼ�Ϊ��"+n_Value+"��\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "str":
		if (n_Value>=12 && n_Value<=30)
		{
			n_Muou_Str = n_Value;
			command("say ľż�ı����ǣ�"+n_Value+"��\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "int":
		if (n_Value>=12 && n_Value<=30)
		{
			n_Muou_Int = n_Value;
			command("say ľż�������ǣ�"+n_Value+"��\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "con":
		if (n_Value>=12 && n_Value<=30)
		{
			n_Muou_Con = n_Value;
			command("say ľż�ĸ����ǣ�"+n_Value+"��\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "dex":
		if (n_Value>=12 && n_Value<=30)
		{
			n_Muou_Dex = n_Value;
			command("say ľż�����ǣ�"+n_Value+"��\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "deathcount":
		if (n_Value>=1 && n_Value<=600)
		{
			n_Muou_Deathcount = n_Value;
			command("say ľż����Ч���������ǣ�"+n_Value+"��\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "pxj":
		if (n_Value==1)
		{
			n_Muou_Pxj = 1;
			command("say ľż����ʹ�ñ�а����\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "default":
		if (n_Value==1)
		{
			n_Muou_Age = 60;
			n_Muou_Skills_Level = 400;
			n_Muou_Xinfa_Level = 400;
			n_Muou_Str = 20;
			n_Muou_Int = 20;
			n_Muou_Con = 30;
			n_Muou_Dex = 20;
			n_Muou_Deathcount = 100;
			n_Muou_Pxj = 0;							// Muou cannot use pxj by default
			command("say ľż�����Ϊ��"+n_Muou_Age+"�ꡣ\n");
			command("say ľż�ļ��ܵȼ�Ϊ��"+n_Muou_Skills_Level+"��\n");
			command("say ľż���ķ��ȼ�Ϊ��"+n_Muou_Xinfa_Level+"��\n");
			command("say ľż�ı����ǣ�"+n_Muou_Str+"��\n");
			command("say ľż�������ǣ�"+n_Muou_Int+"��\n");
			command("say ľż�ĸ����ǣ�"+n_Muou_Con+"��\n");
			command("say ľż�����ǣ�"+n_Muou_Dex+"��\n");
			command("say ľż����Ч���������ǣ�"+n_Muou_Deathcount+"��\n");
			command("say ľż����ʹ�ñ�а����");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "menpai":
		switch(s_Value)
		{
		case "shaolin":
			s_Muou_Menpai = "������";
			command("say ľż��"+s_Muou_Menpai+"�ġ�\n");
			Check_User_Input(me);
			return 1;
		break;
		case "wudang":
			s_Muou_Menpai = "�䵱��";
			command("say ľż��"+s_Muou_Menpai+"�ġ�\n");
			Check_User_Input(me);
			return 1;
		break;
		case "quanzhen":
			s_Muou_Menpai = "ȫ���";
			command("say ľż��"+s_Muou_Menpai+"�ġ�\n");
			Check_User_Input(me);
			return 1;
		break;
		case "gumu":
			s_Muou_Menpai = "��Ĺ��";
			command("say ľż��"+s_Muou_Menpai+"�ġ�\n");
			Check_User_Input(me);
			return 1;
		break;
		case "kunlun":
			s_Muou_Menpai = "������";
			command("say ľż��"+s_Muou_Menpai+"�ġ�\n");
			Check_User_Input(me);
			return 1;
		break;
		case "gaibang":
			s_Muou_Menpai = "ؤ��";
			command("say ľż��"+s_Muou_Menpai+"�ġ�\n");
			Check_User_Input(me);
			return 1;
		break;
		case "emei":
			s_Muou_Menpai = "������";
			command("say ľż��"+s_Muou_Menpai+"�ġ�\n");
			Check_User_Input(me);
			return 1;
		break;
		case "huashan":
			s_Muou_Menpai = "��ɽ��";
			command("say ľż��"+s_Muou_Menpai+"�ġ�\n");
			Check_User_Input(me);
			return 1;
		break;
		case "taohua":
			s_Muou_Menpai = "�һ���";
			command("say ľż��"+s_Muou_Menpai+"�ġ�\n");
			Check_User_Input(me);
			return 1;
		break;
		case "dali":
			s_Muou_Menpai = "����μ�";
			command("say ľż��"+s_Muou_Menpai+"�ġ�\n");
			Check_User_Input(me);
			return 1;
		break;
		case "xingxiu":
			s_Muou_Menpai = "������";
			command("say ľż��"+s_Muou_Menpai+"�ġ�\n");
			Check_User_Input(me);
			return 1;
		break;
		case "xueshan":
			s_Muou_Menpai = "ѩɽ��";
			command("say ľż��"+s_Muou_Menpai+"�ġ�\n");
			Check_User_Input(me);
			return 1;
		break;
		case "baituo":
			s_Muou_Menpai = "����ɽ";
			command("say ľż��"+s_Muou_Menpai+"�ġ�\n");
			Check_User_Input(me);
			return 1;
		break;
		default:
			return notify_fail("��������û��������ɣ���������ơ�\n");
		break;
		}
	break;
	default:
		return notify_fail("��Ƴ�����������ơ�\n");
	break;
	}
	return notify_fail("��Ƴ�����������������Ŀ��\n");
	return 1;
}

void Reset_Yiren()
{
	if(objectp(Obj_Player_A))
	{
		Obj_Player_A->delete_temp("n_Muou_Cannot_Leave");
	}
	if(objectp(Obj_Player_B))
	{
		Obj_Player_B->delete_temp("n_Muou_Cannot_Leave");
	}
	// Delete all vars
	Obj_Yiren->delete_temp("A_Paid_Gold");
	Obj_Yiren->delete_temp("A_Started_Setup");
	Obj_Yiren->delete_temp("A_Finish_Setup");
	Obj_Yiren->delete_temp("B_Paid_Gold");
	Obj_Yiren->delete_temp("B_Started_Setup");
	Obj_Yiren->delete_temp("B_Finish_Setup");
	Obj_Yiren->delete_temp("Player_A");
	Obj_Yiren->delete_temp("Player_B");
	Obj_Yiren->delete_temp("Both_Paid");
	Obj_Player_A=0;
	Obj_Player_B=0;

	// Destruct muou if there is any
	if(objectp(Obj_Muou_A) && !interactive(Obj_Muou_A))	// If Player not controlling muou
	{
		destruct(Obj_Muou_A);
	}
	if(objectp(Obj_Muou_B) && !interactive(Obj_Muou_B)) // If player not controlling muou
	{
		destruct(Obj_Muou_B);
	}

	Reset_All_Vars(); // Reset all vars
}

void Reset_All_Vars()
{
	// Reset all vars
	s_Muou_Menpai = 0;
	n_Muou_Age = 0;
	n_Muou_Skills_Level = 0;
	n_Muou_Xinfa_Level = 0;
	n_Muou_Str = 0;
	n_Muou_Int = 0;
	n_Muou_Con = 0;
	n_Muou_Dex = 0;
	n_Muou_Deathcount = 0;
	n_Muou_Pxj = 0;							// Muou cannot use pxj by default
	return;
}

void Check_User_Input(object me)
{
	// Check and tell the inputer what is missing and needs to input:
	if (!s_Muou_Menpai)
	{
		tell_object(me,"�㻹Ҫ���ľż�����ɣ�\n");
	}
	else // In case player's menpai choise is gaibang and deathcount is 0
	{
		if (s_Muou_Menpai=="ؤ��" && !n_Muou_Deathcount)
		{
			tell_object(me, "�㻹Ҫ���ľż����Ч����������\n");
		}
	}
	if (!n_Muou_Age)
	{
		tell_object(me,"�㻹Ҫ���ľż�����䣡\n");
	}
	if (!n_Muou_Skills_Level)
	{
		tell_object(me,"�㻹Ҫ���ľż���书�ȼ���\n");
	}
	if (!n_Muou_Xinfa_Level)
	{
		tell_object(me,"�㻹Ҫ���ľż���ķ��ȼ���\n");
	}
	if (!n_Muou_Str)
	{
		tell_object(me,"�㻹Ҫ���ľż�ı�����\n");
	}
	if (!n_Muou_Int)
	{
		tell_object(me,"�㻹Ҫ���ľż��������\n");
	}
	if (!n_Muou_Con)
	{
		tell_object(me,"�㻹Ҫ���ľż�ĸ��ǣ�\n");
	}
	if (!n_Muou_Dex)
	{
		tell_object(me,"�㻹Ҫ���ľż������\n");
	}

	// If all input is finished
	if(s_Muou_Menpai && n_Muou_Age && n_Muou_Skills_Level && n_Muou_Xinfa_Level && n_Muou_Str && n_Muou_Int && n_Muou_Con && n_Muou_Dex)
	{
		// If total gifts is in range
		if (n_Muou_Str+n_Muou_Int+n_Muou_Con+n_Muou_Dex>=1 && n_Muou_Str+n_Muou_Int+n_Muou_Con+n_Muou_Dex<=90)
		{
			if (n_Muou_Deathcount<=0) // If deathcount is 0, set to 100.
			{
				n_Muou_Deathcount = 100;
			}
			if (me == Obj_Player_A || me == Obj_Player_B) //
			{
				remove_call_out("Auto_Set");	// Remove the call out
				Set_Muou(me); // Set muou's exp, skills and etc.
			}
			
		}
		else // If total gifts is out of range
		{
			tell_object(me,"ľż���츳�ܺͳ�����ʮ�����������츳���ܺͲ��ܳ�����ʮ��\n");
		}
	}
}

// Set muou's exp, skills and etc.
void Set_Muou(object Obj_Muou_Owner)
{
	object Obj_Muou;

	// Setup NPC:
	Obj_Muou = new("/d/city/npc/muou.c");				// Clone the NPC
	Obj_Muou->set_temp("Obj_Owner", Obj_Muou_Owner);	// Set owner
	Obj_Muou->set_temp("Obj_Yiren", Obj_Yiren);			// Set Yiren object link in NPC
	// Set exp, skills and etc.
	Obj_Muou->set_skills(Obj_Muou, s_Muou_Menpai, n_Muou_Age, n_Muou_Skills_Level, n_Muou_Xinfa_Level, n_Muou_Str, n_Muou_Int, n_Muou_Con, n_Muou_Dex, n_Muou_Deathcount, n_Muou_Pxj);
	Obj_Muou->setup();									// Start heart beat etc.
	Obj_Muou->move("/d/city/muoult");				// Set NPC location
	command("emote ��һ��ľż������ľż̨��\n");

	// If the player is online and make sure he is not finish his setup yet
	if(objectp(Obj_Player_A) && Obj_Yiren->query_temp("A_Started_Setup"))
	{
		// Player A is finish setup, change flags, make sure setmuou command is not open for him:
		Obj_Yiren->set_temp("A_Started_Setup", 0);			// Setup is finished
		Obj_Yiren->set_temp("A_Finish_Setup", 1);			// Setup is finished
		// Chat out everything
		command("jiaoyi "+Obj_Player_A->query("name")+"�����һ��"+n_Muou_Age+"�꣬"+s_Muou_Menpai+"��ľż��");
		command("jiaoyi �书�ȼ���"+n_Muou_Skills_Level+"���ķ��ȼ���"+n_Muou_Xinfa_Level+"���츳�ǣ�"+n_Muou_Str+"��"+n_Muou_Int+"��"+n_Muou_Con+"��"+n_Muou_Dex+"��");
		command("jiaoyi ��Ч����"+n_Muou_Deathcount+"�Σ�����Ը���������һ��ľż��"+Obj_Player_A->query("name")+"��һ��Ϸ��\n");
		Reset_All_Vars();									// Reset all global vars when the muou is cloned
		Obj_Muou_A = Obj_Muou;
		remove_call_out("B_Not_Come");						// If no one antoher player come in time
		call_out("B_Not_Come", 120);
	} // If the player is online and make sure he is not finish his setup yet
	else if(objectp(Obj_Player_B) && objectp(Obj_Player_A) && Obj_Yiren->query_temp("B_Started_Setup"))
	{
		// Player B is finish setup, change flags, make sure setmuou command is not open for him:
		Obj_Yiren->set_temp("B_Started_Setup", 0);			// Setup is finished
		Obj_Yiren->set_temp("B_Finish_Setup", 1);			// Setup is finished
		// Chat out everything
		command("jiaoyi "+Obj_Player_B->query("name")+"�����һ��"+n_Muou_Age+"�꣬"+s_Muou_Menpai+"��ľż��");
		command("jiaoyi �书�ȼ���"+n_Muou_Skills_Level+"���ķ��ȼ���"+n_Muou_Xinfa_Level+"���츳�ǣ�"+n_Muou_Str+"��"+n_Muou_Int+"��"+n_Muou_Con+"��"+n_Muou_Dex+"��");
		command("jiaoyi ��Ч����"+n_Muou_Deathcount+"�Σ�Ҫ��"+Obj_Player_A->query("name")+"��Ƶ�ľż��һ��Ϸ��ľż�����ڿ�ʼ��\n");
		Obj_Muou_B = Obj_Muou;
		Obj_Yiren->set_temp("Both_Paid", 1);
		Obj_Muou_A->set_temp("o_Opponent", Obj_Muou_B);
		Obj_Muou_B->set_temp("o_Opponent", Obj_Muou_A);
		remove_call_out("Muou_Fight");
		call_out("Muou_Fight", 0);
	}
	else // Player not online
	{
		command ("say �ף���ô�˲����ˣ����Ǹ��ҿ���Ц�ɣ���һ��Ҫ����ϡ�");
		Reset_Yiren(); // Reset
		destruct(Obj_Muou);
		return;
	}
	return;
}

// Auto set muou's parameters when the muou setup time is over.
void Auto_Set(object who)
{
	// If the money giver is missing
	if(!objectp(who))
	{
		command("say ��֣�����ȥ�ˣ�������");
		Reset_Yiren();
		return;
	}
	s_Muou_Menpai = "������";
	n_Muou_Age = 80;
	n_Muou_Skills_Level = 400;
	n_Muou_Xinfa_Level = 400;
	n_Muou_Str = 20;
	n_Muou_Int = 20;
	n_Muou_Con = 30;
	n_Muou_Dex = 20;
	n_Muou_Deathcount = 100;
	command("say ����ô����ô�ð����һ�Ҫ�������ء������Ұ�����һ���ɡ�");
	Set_Muou(who);
	return;
}

void B_Not_Come()
{
	command("chat ʱ�䵽�ˣ�û����Ը���"+Obj_Player_A->query("name")+"��Ƶ�ľż��һ�ܣ��ⳡľż��ȡ����");
	Reset_Yiren();
	return;
}

void Muou_Fight()
{
	if(Obj_Player_A && Obj_Player_B && Obj_Muou_A && Obj_Muou_B);	// If all objects are not empty
	{
		if(!find_player(Obj_Player_A->query("id")) || !find_player(Obj_Player_B->query("id")))	// Ensure both players are online
		{
			command ("say �ף���ô�˲����ˣ����Ǹ��ҿ���Ц�ɣ���һ��Ҫ����ϡ�");
			Reset_Yiren();
			return;
		}
		
		if( !Obj_Muou_A || !living(Obj_Muou_A))
		{
			tell_object(Obj_Player_A, "����û��������\n");
			return;
		}

		if( Obj_Muou_A->query_temp("body_ob") )
		{
			tell_object(Obj_Player_A, "�����ڲ������ľż��\n");
			return;
		}
		LOGIN_D->enter_world(Obj_Player_A, Obj_Muou_A, 1);
		message_vision(HIW+"$Nһ���������Ļ��ߣ���ʼ����ľż��\n"+NOR, Obj_Player_A);
		tell_object(Obj_Muou_A, HIW+"��һ���������Ļ��ߣ���ʼ����ľż��\n"+NOR);
		tell_object(Obj_Muou_A, "ľż��һ���Ӻ�ʼ����׼������enable, bei�ȵȡ�����\n");
		
		if( !Obj_Muou_B || !living(Obj_Muou_B))
		{
			tell_object(Obj_Player_B, "����û��������\n");
			return;
		}
		if( Obj_Muou_B->query_temp("body_ob") )
		{
			tell_object(Obj_Player_B, "�Ѿ������ڲ������ľż�ˡ�\n");
			return;
		}
		LOGIN_D->enter_world(Obj_Player_B, Obj_Muou_B, 1);
		message_vision(HIW+"$Nһ���������Ļ��ߣ���ʼ����ľż��\n"+NOR, Obj_Player_B);
		tell_object(Obj_Muou_B, "\nĿǰȨ�ޣ�" + wizhood(Obj_Muou_B) + "\n");
		tell_object(Obj_Muou_B, "ľż��һ���Ӻ�ʼ����׼������enable, bei�ȵȡ�����\n");
		remove_call_out("Start_Fight");
		call_out("Start_Fight", 60);
	}
	return;
}

void Start_Fight()
{
	if(objectp(Obj_Muou_A) && objectp(Obj_Muou_B))
	{
		command("say ľż�����ڿ�ʼ��\n");
		tell_object(Obj_Muou_A, "ľż�����ڿ�ʼ��\n");
		tell_object(Obj_Muou_B, "ľż�����ڿ�ʼ��\n");
		Obj_Muou_A->kill_ob(Obj_Muou_B);
		Obj_Muou_B->kill_ob(Obj_Muou_A);
	}
	remove_call_out("Finish_Fight");
	call_out("Finish_Fight", 300);
}

void Finish_Fight()
{
	command("say ��ô��������ô�ð����һ�Ҫ�������أ���׼���ˣ�");
	if(objectp(Obj_Muou_A) && interactive(Obj_Muou_A))
	{
		Obj_Muou_A->quit(Obj_Muou_A);
	}
	if(objectp(Obj_Muou_B) && interactive(Obj_Muou_B))
	{
		Obj_Muou_B->quit(Obj_Muou_B);
	}
	Reset_Yiren();
}