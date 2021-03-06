// By FunBoo@shenzhou
// Yiren.C 艺人

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
	set_name("艺人", ({"yiren", "yi ren"}));
	set("gender", "男性");
	set("age", 60);
	set("long", "他是一个木偶剧艺人，以演木偶剧为生。\n"+"如果你给他十两黄金，他就会让你自己来设计和操纵木偶。\n");
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
		message("vision", me->name(1)+"急急忙忙地离开了.\n", environment(me), me);
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
				command("say "+Obj_Player_A->query("name")+"和"+Obj_Player_B->query("name")+"正在演木偶戏，你等一下。\n");
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
				command ("say 咦？怎么人不见了？不是跟我开玩笑吧？下一个要玩的上。");
			}
			// Not accept money
			return 0;
		}

		// If A is paid and A's setup is not finish yet
		if (Obj_Yiren->query_temp("A_Paid_Gold") && !Obj_Yiren->query_temp("A_Finish_Setup"))
		{
			tell_object(who, "艺人告诉你："+Obj_Player_A->query("name")+"正在设计木偶，请等一下。\n");
			return 0;
		}

		// If B is paid and B's setup is not finish yet
		if(Obj_Yiren->query_temp("B_Paid_Gold") && !Obj_Yiren->query_temp("B_Finish_Setup"))
		{
			tell_object(who, "艺人告诉你："+Obj_Player_B->query("name")+"正在设计木偶，请等一下。\n");
			return 0;
		}

		// If the money giver is PlayerA or Player B, and their setup is already finish:
		if(who == Obj_Yiren->query_temp("Player_A") || who == Obj_Yiren->query_temp("Player_B"))
		{
			tell_object(who, "你已经给钱了，还给什么钱？\n");
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
			command("say 你可以开始设计你自己的木偶了。\n");
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
			command("say 你可以开始设计你自己的木偶了。\n");

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
		command("say 财源广进多多益善，来者不拒！");
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
		return notify_fail("你要设计什么？\n");
	}

	// If player A is the one who should do setup, and he is not finish his setup yet OR
	// If player B is the one who should do setup, and he is not finish his setup yet
	if ((Obj_Yiren->query_temp("A_Paid_Gold") && Obj_Yiren->query_temp("A_Started_Setup") && !Obj_Yiren->query_temp("A_Finish_Setup") && me==Obj_Player_A) || (Obj_Yiren->query_temp("B_Paid_Gold") && Obj_Yiren->query_temp("B_Started_Setup") && !Obj_Yiren->query_temp("B_Finish_Setup") && me==Obj_Player_B));
	else // If not
	{
		tell_object(me, "对不起，你现在不能设计木偶。\n");
		return 1;
	}

	// If the input is correct
	if(sscanf(setting, "%s %d", s_Name, n_Value)==2 || sscanf(setting, "%s %s", s_Name, s_Value)==2);
	else // If input is incorrect
	{
		return notify_fail("输入错误，请重来。\n");
		return 1;
	}
	
	switch(s_Name)
	{
	case "age":
		if (n_Value>=20 && n_Value<=200)
		{
			n_Muou_Age = n_Value;
			command("say 木偶的年纪为："+n_Value+"岁。\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "skill":
		if (n_Value>=1 && n_Value<=800)
		{
			n_Muou_Skills_Level = n_Value;
			command("say 木偶的技能等级为："+n_Value+"。\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "xinfa":
		if (n_Value>=1 && n_Value<=800)
		{
			n_Muou_Xinfa_Level = n_Value;
			command("say 木偶的心法等级为："+n_Value+"。\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "str":
		if (n_Value>=12 && n_Value<=30)
		{
			n_Muou_Str = n_Value;
			command("say 木偶的臂力是："+n_Value+"。\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "int":
		if (n_Value>=12 && n_Value<=30)
		{
			n_Muou_Int = n_Value;
			command("say 木偶的智力是："+n_Value+"。\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "con":
		if (n_Value>=12 && n_Value<=30)
		{
			n_Muou_Con = n_Value;
			command("say 木偶的根骨是："+n_Value+"。\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "dex":
		if (n_Value>=12 && n_Value<=30)
		{
			n_Muou_Dex = n_Value;
			command("say 木偶的身法是："+n_Value+"。\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "deathcount":
		if (n_Value>=1 && n_Value<=600)
		{
			n_Muou_Deathcount = n_Value;
			command("say 木偶的有效死亡次数是："+n_Value+"。\n");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "pxj":
		if (n_Value==1)
		{
			n_Muou_Pxj = 1;
			command("say 木偶可以使用辟邪剑。\n");
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
			command("say 木偶的年纪为："+n_Muou_Age+"岁。\n");
			command("say 木偶的技能等级为："+n_Muou_Skills_Level+"。\n");
			command("say 木偶的心法等级为："+n_Muou_Xinfa_Level+"。\n");
			command("say 木偶的臂力是："+n_Muou_Str+"。\n");
			command("say 木偶的智力是："+n_Muou_Int+"。\n");
			command("say 木偶的根骨是："+n_Muou_Con+"。\n");
			command("say 木偶的身法是："+n_Muou_Dex+"。\n");
			command("say 木偶的有效死亡次数是："+n_Muou_Deathcount+"。\n");
			command("say 木偶不能使用辟邪剑。");
			Check_User_Input(me);
			return 1;
		}
	break;
	case "menpai":
		switch(s_Value)
		{
		case "shaolin":
			s_Muou_Menpai = "少林派";
			command("say 木偶是"+s_Muou_Menpai+"的。\n");
			Check_User_Input(me);
			return 1;
		break;
		case "wudang":
			s_Muou_Menpai = "武当派";
			command("say 木偶是"+s_Muou_Menpai+"的。\n");
			Check_User_Input(me);
			return 1;
		break;
		case "quanzhen":
			s_Muou_Menpai = "全真教";
			command("say 木偶是"+s_Muou_Menpai+"的。\n");
			Check_User_Input(me);
			return 1;
		break;
		case "gumu":
			s_Muou_Menpai = "古墓派";
			command("say 木偶是"+s_Muou_Menpai+"的。\n");
			Check_User_Input(me);
			return 1;
		break;
		case "kunlun":
			s_Muou_Menpai = "昆仑派";
			command("say 木偶是"+s_Muou_Menpai+"的。\n");
			Check_User_Input(me);
			return 1;
		break;
		case "gaibang":
			s_Muou_Menpai = "丐帮";
			command("say 木偶是"+s_Muou_Menpai+"的。\n");
			Check_User_Input(me);
			return 1;
		break;
		case "emei":
			s_Muou_Menpai = "峨嵋派";
			command("say 木偶是"+s_Muou_Menpai+"的。\n");
			Check_User_Input(me);
			return 1;
		break;
		case "huashan":
			s_Muou_Menpai = "华山派";
			command("say 木偶是"+s_Muou_Menpai+"的。\n");
			Check_User_Input(me);
			return 1;
		break;
		case "taohua":
			s_Muou_Menpai = "桃花岛";
			command("say 木偶是"+s_Muou_Menpai+"的。\n");
			Check_User_Input(me);
			return 1;
		break;
		case "dali":
			s_Muou_Menpai = "大理段家";
			command("say 木偶是"+s_Muou_Menpai+"的。\n");
			Check_User_Input(me);
			return 1;
		break;
		case "xingxiu":
			s_Muou_Menpai = "星宿派";
			command("say 木偶是"+s_Muou_Menpai+"的。\n");
			Check_User_Input(me);
			return 1;
		break;
		case "xueshan":
			s_Muou_Menpai = "雪山派";
			command("say 木偶是"+s_Muou_Menpai+"的。\n");
			Check_User_Input(me);
			return 1;
		break;
		case "baituo":
			s_Muou_Menpai = "白驼山";
			command("say 木偶是"+s_Muou_Menpai+"的。\n");
			Check_User_Input(me);
			return 1;
		break;
		default:
			return notify_fail("神州现在没有这个门派，请重新设计。\n");
		break;
		}
	break;
	default:
		return notify_fail("设计出错，请重新设计。\n");
	break;
	}
	return notify_fail("设计出错，请重新设计这个项目。\n");
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
		tell_object(me,"你还要设计木偶的门派！\n");
	}
	else // In case player's menpai choise is gaibang and deathcount is 0
	{
		if (s_Muou_Menpai=="丐帮" && !n_Muou_Deathcount)
		{
			tell_object(me, "你还要设计木偶的有效死亡次数！\n");
		}
	}
	if (!n_Muou_Age)
	{
		tell_object(me,"你还要设计木偶的年龄！\n");
	}
	if (!n_Muou_Skills_Level)
	{
		tell_object(me,"你还要设计木偶的武功等级！\n");
	}
	if (!n_Muou_Xinfa_Level)
	{
		tell_object(me,"你还要设计木偶的心法等级！\n");
	}
	if (!n_Muou_Str)
	{
		tell_object(me,"你还要设计木偶的臂力！\n");
	}
	if (!n_Muou_Int)
	{
		tell_object(me,"你还要设计木偶的智力！\n");
	}
	if (!n_Muou_Con)
	{
		tell_object(me,"你还要设计木偶的根骨！\n");
	}
	if (!n_Muou_Dex)
	{
		tell_object(me,"你还要设计木偶的身法！\n");
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
			tell_object(me,"木偶的天赋总和超过九十，请从新设计天赋，总和不能超过九十。\n");
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
	command("emote 把一个木偶放上了木偶台。\n");

	// If the player is online and make sure he is not finish his setup yet
	if(objectp(Obj_Player_A) && Obj_Yiren->query_temp("A_Started_Setup"))
	{
		// Player A is finish setup, change flags, make sure setmuou command is not open for him:
		Obj_Yiren->set_temp("A_Started_Setup", 0);			// Setup is finished
		Obj_Yiren->set_temp("A_Finish_Setup", 1);			// Setup is finished
		// Chat out everything
		command("jiaoyi "+Obj_Player_A->query("name")+"设计了一个"+n_Muou_Age+"岁，"+s_Muou_Menpai+"的木偶。");
		command("jiaoyi 武功等级："+n_Muou_Skills_Level+"，心法等级："+n_Muou_Xinfa_Level+"，天赋是："+n_Muou_Str+"，"+n_Muou_Int+"，"+n_Muou_Con+"，"+n_Muou_Dex+"。");
		command("jiaoyi 有效死亡"+n_Muou_Deathcount+"次，有人愿意设计另外一个木偶和"+Obj_Player_A->query("name")+"演一出戏吗？\n");
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
		command("jiaoyi "+Obj_Player_B->query("name")+"设计了一个"+n_Muou_Age+"岁，"+s_Muou_Menpai+"的木偶。");
		command("jiaoyi 武功等级："+n_Muou_Skills_Level+"，心法等级："+n_Muou_Xinfa_Level+"，天赋是："+n_Muou_Str+"，"+n_Muou_Int+"，"+n_Muou_Con+"，"+n_Muou_Dex+"。");
		command("jiaoyi 有效死亡"+n_Muou_Deathcount+"次，要和"+Obj_Player_A->query("name")+"设计的木偶演一出戏。木偶剧现在开始！\n");
		Obj_Muou_B = Obj_Muou;
		Obj_Yiren->set_temp("Both_Paid", 1);
		Obj_Muou_A->set_temp("o_Opponent", Obj_Muou_B);
		Obj_Muou_B->set_temp("o_Opponent", Obj_Muou_A);
		remove_call_out("Muou_Fight");
		call_out("Muou_Fight", 0);
	}
	else // Player not online
	{
		command ("say 咦？怎么人不见了？不是跟我开玩笑吧？下一个要玩的上。");
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
		command("say 奇怪，人哪去了？重来。");
		Reset_Yiren();
		return;
	}
	s_Muou_Menpai = "少林派";
	n_Muou_Age = 80;
	n_Muou_Skills_Level = 400;
	n_Muou_Xinfa_Level = 400;
	n_Muou_Str = 20;
	n_Muou_Int = 20;
	n_Muou_Con = 30;
	n_Muou_Dex = 20;
	n_Muou_Deathcount = 100;
	command("say 你怎么搞那么久啊？我还要做生意呢。来！我帮你做一个吧。");
	Set_Muou(who);
	return;
}

void B_Not_Come()
{
	command("chat 时间到了，没有人愿意和"+Obj_Player_A->query("name")+"设计的木偶打一架，这场木偶剧取消。");
	Reset_Yiren();
	return;
}

void Muou_Fight()
{
	if(Obj_Player_A && Obj_Player_B && Obj_Muou_A && Obj_Muou_B);	// If all objects are not empty
	{
		if(!find_player(Obj_Player_A->query("id")) || !find_player(Obj_Player_B->query("id")))	// Ensure both players are online
		{
			command ("say 咦？怎么人不见了？不是跟我开玩笑吧？下一个要玩的上。");
			Reset_Yiren();
			return;
		}
		
		if( !Obj_Muou_A || !living(Obj_Muou_A))
		{
			tell_object(Obj_Player_A, "这里没有这个生物。\n");
			return;
		}

		if( Obj_Muou_A->query_temp("body_ob") )
		{
			tell_object(Obj_Player_A, "有人在操纵你的木偶。\n");
			return;
		}
		LOGIN_D->enter_world(Obj_Player_A, Obj_Muou_A, 1);
		message_vision(HIW+"$N一弯腰到了帷幕后边，开始操纵木偶。\n"+NOR, Obj_Player_A);
		tell_object(Obj_Muou_A, HIW+"你一弯腰到了帷幕后边，开始操纵木偶。\n"+NOR);
		tell_object(Obj_Muou_A, "木偶剧一分钟后开始，请准备：如enable, bei等等。。。\n");
		
		if( !Obj_Muou_B || !living(Obj_Muou_B))
		{
			tell_object(Obj_Player_B, "这里没有这个生物。\n");
			return;
		}
		if( Obj_Muou_B->query_temp("body_ob") )
		{
			tell_object(Obj_Player_B, "已经有人在操纵你的木偶了。\n");
			return;
		}
		LOGIN_D->enter_world(Obj_Player_B, Obj_Muou_B, 1);
		message_vision(HIW+"$N一弯腰到了帷幕后边，开始操纵木偶。\n"+NOR, Obj_Player_B);
		tell_object(Obj_Muou_B, "\n目前权限：" + wizhood(Obj_Muou_B) + "\n");
		tell_object(Obj_Muou_B, "木偶剧一分钟后开始，请准备：如enable, bei等等。。。\n");
		remove_call_out("Start_Fight");
		call_out("Start_Fight", 60);
	}
	return;
}

void Start_Fight()
{
	if(objectp(Obj_Muou_A) && objectp(Obj_Muou_B))
	{
		command("say 木偶剧现在开始！\n");
		tell_object(Obj_Muou_A, "木偶剧现在开始！\n");
		tell_object(Obj_Muou_B, "木偶剧现在开始！\n");
		Obj_Muou_A->kill_ob(Obj_Muou_B);
		Obj_Muou_B->kill_ob(Obj_Muou_A);
	}
	remove_call_out("Finish_Fight");
	call_out("Finish_Fight", 300);
}

void Finish_Fight()
{
	command("say 怎么有人玩那么久啊？我还要做生意呢，不准玩了！");
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