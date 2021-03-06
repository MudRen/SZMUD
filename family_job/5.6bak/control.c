// control.c
// CODE BY SCATTER
#include <ansi.h>
inherit ROOM;

string vermsg="\n\n(V 5.6B 正式版)\n";
//****** GLOBAL VAR ********
void get_player();
void detect_menpai(object me, string strName, string strId, string strFName, int intExp);
void create_path(object me, string strName, string strId, string strFName, int intExp, string strMenpai, string strMsg, string strDir, string strCPlace);
void create_msg(object me, object room, string strMsg, string strDir, object npc, string strCPlace);
void final_count();
void do_set_skill(object me, object room, string strMsg, string strDir, string strCPlace, string roomx);
private int copy_skill(object npc, object me);
//**************************



//**** MENPAI KILLER JOB ***
void menpai_killer(object me, string strName, string strId, string strFName, int intExp);
//**************************


//**** MENPAI QUESTION JOB ***
void menpai_question(object me, string strName, string strId, string strFName, int intExp);
//****************************

void create()
{
        set("short", HIY"门派工作控制室"NOR);
        set("channel_id", "主动工作系统(AAJ)");
        set("long", "功能如下\n启动 (start_job)\n关闭 (stop_job)\n启动一次工作 (give_job)\n设定发放时间 (set_time <时间>)\n\n");

		set("exits", ([
        "out" : "/d/wizard/meeting_room"]));
		seteuid(getuid());
        set("no_refresh",1);
        setup();
}

void init()
{
        add_action("start_job", "start_job");
        add_action("stop_job", "stop_job");
        add_action("give_job", "give_job");
        add_action("do_set_time", "set_time");
}

int do_set_time(string arg)
{
        if(!arg)
        {
                write("格式错误\n");
                return 1;
        }

        set("looptime", arg);
		CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIR"天地间突然晃动了一下，瞬间流星从东方的空中划了过去。"));
        CHANNEL_D->do_channel(this_object(), "sys", sprintf("发放工作时间设定改为 %s 秒。", arg));
        return 1;
}



int stop_job(string arg)
{
        if(!query_temp("job_enable"))
        {
                write("工作系统以本来就是关闭的\n");
                return 1;
        }
        CHANNEL_D->do_channel(this_object(), "sys", sprintf("自动分发工作系统关闭。"));
		CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIR"天空中的彩虹慢慢的消失，看来这其中藏有玄机。"));
        delete_temp("job_enable");
        return 1;
}

int start_job(string arg)
{
        if(query_temp("job_enable"))
        {
                write("工作系统以启动\n");
                return 1;
        }

        CHANNEL_D->do_channel(this_object(), "sys", sprintf("自动分发工作系统启动。"));
		CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIR"突然天地间有一股说不说来的压力，天空上慢慢的出现了一到彩虹，看来这其中藏有玄机。"));
        set_temp("job_enable", 1);
        get_player();
        return 1;
}

void get_player()
{
        object me, *list;
        string strName, strId, strFName;
        int j, total, intExp;


        if(!query_temp("job_enable"))
        {
                write("工作终止\n");
                return;
        }

        list = users();
        total = sizeof(list);
        j = random(total);
        list[j]->short(1);
        me = list[j];

        if(me->query("combat_exp") < 100000)
        {
                get_player();
                //write("PLAYER SKIP\n");
                return;
        }


		if( (environment(me)->query("no_fight")) == 1)
        {
                get_player();
                write("PLAYER SKIP BECAUSE IN NO FIGHTING ROOM\n");
                return;
        }

        if(!me->query("env/family_job"))
        {
                get_player();
                //write("PLAYER SKIP\n");
                return;
        }

        write(me->query("name")+"\n");
        write(me->query("id")+"\n");
        write(me->query("combat_exp")+"\n");
        write(me->query("family/family_name")+"\n");

        strName = me->query("name");
        strId = me->query("id");
        intExp = me->query("combat_exp");
        strFName = me->query("family/family_name");

		switch(random(3))
		{
		case 0:
			{
				detect_menpai(me, strName, strId, strFName, intExp);
				break;
			}
		case 1:
			{
				menpai_killer(me, strName, strId, strFName, intExp);
				break;
			}

		case 2:
			{
				menpai_question(me, strName, strId, strFName, intExp);
				break;
			}

		default:
			{
				detect_menpai(me, strName, strId, strFName, intExp);
				break;
			}
		}

        return;
}


//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//********************   Menpai QUESTION Star Here   **************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************

void menpai_question(object me, string strName, string strId, string strFName, int intExp)
{
	object npc;
	string strMsg, answer, qn;
	int r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16;
	r1 = random(5) + 5;
	r2 = random(5) + 10;
	r3 = random(5) + 15;
	r4 = random(5) + 20;
	r5 = random(5) + 25;
	r6 = random(5) + 30;
	r7 = random(5) + 35;
	r8 = random(5) + 40;
	r9 = random(5) + 45;
	r10 = random(5) + 50;
	r11 = random(5) + 55;
	r12 = random(5) + 60;
	r13 = random(5) + 65;
	r14 = random(5) + 70;
	r15 = random(5) + 75;
	r16 = random(5) + 80;


	switch(random(9))
	{
	case 0:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r1+" * "+r2+" * "+r3+" * "+r4+" * "+r5+" *\n";
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r6+" *  1 *  4 *  7 * "+r16+" *\n";
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r7+" *  2 *  5 *  8 * "+r15+" *\n";
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r8+" *  3 *  6 *  9 * "+r14+" *\n";
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r9+" * "+r10+" * "+r11+" * "+r12+" * "+r3+" *\n";
			strMsg = strMsg + "**************************\n";

			answer = "2t"+r10+" "+r10+"t"+r16+" "+r16+"t1 1t9";

			tell_object(me, strMsg);
			tell_object(me, HIW"以上是某门派的阵形，如果要破解必须在四条线内将一到九全部碰到\n一但完成这个阵就不攻自破了，你有六十秒的时间思考"NOR);
			tell_object(me, NOR"\n回答方法使用点对点方式，如果从一碰到三然后三碰到九然后九碰到七最后七到一，指令为 ans 1t3 3t9 9t7 7t1，\n"NOR);
			tell_object(me, NOR"请在这里回答 (起始直是 2)\n"NOR);
			qn="G1";
			break;
		}
	case 1:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + "一夫，二郎，三吉，四祥，五平五个人，是青梅竹马的好朋友，如今长大成人，\n";
			strMsg = strMsg + "各自当上面包店老板，理发师，肉店老板，菸酒经销商和公司职员。\n\n";
			strMsg = strMsg + "1.面包店老板不是三吉，也不是四祥。\n";
			strMsg = strMsg + "2.菸酒经销商不是四祥，也不是一夫。\n";
			strMsg = strMsg + "3.此外，三吉和五平住在同一栋公寓，隔壁是公司职员的家。\n";
			strMsg = strMsg + "4.三吉娶理发师的女儿时，二郎是他们的媒人。\n";
			strMsg = strMsg + "5.一夫和三吉有空时，就和肉店老板，面包店老板打牌。\n";
			strMsg = strMsg + "6.而且，每隔十天，四祥和五平一定要到理发店修个脸。\n";
			strMsg = strMsg + "7.但是，公司职员则一向自己刮胡子，从来不到理发店去。\n\n";
			strMsg = strMsg + "问题 : 请将这五个人的职业按照顺序写出来，用空格来分开\n";
			strMsg = strMsg + "(使用 ans <一夫的职业> <二郎的职业> <三吉的职业> <四祥的职业> <五平的职业>\n";
			tell_object(me, strMsg);
			tell_object(me, NOR"请在这里回答\n"NOR);
			answer = "理发师 公司职员 菸酒经销商 肉店老板 面包店老板";
			qn="L2";
			break;
		}
	case 2:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + "(4 * 2 / 4) * (4 * 2 / 4) + 4 - 4 * 2 = X\n";
			strMsg = strMsg + "X + 3 + 7 - 4 / 2 - 8 = Y\n";
			strMsg = strMsg + "0 * X + 3 * Y / 3 - 12 = Z\n";
			strMsg = strMsg + "Z * 100 * Y / 100 / 5 * X + 100 - 149 + 49 + Z + 100 = K\n";
			strMsg = strMsg + "\n问题请问 : K 的数值是多少?\n";
			strMsg = strMsg + "使用 ans <答案>\n";
			answer = "88";
			qn="M3";
			tell_object(me, strMsg);
			tell_object(me, NOR"请在这里回答\n"NOR);
			break;
		}
	case 4:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + "(4 * 2 / 4) * (4 * 2 / 4) + 4 - 4 * 2 = X\n";
			strMsg = strMsg + "X + 3 + 7 - 4 / 2 - 8 = Y\n";
			strMsg = strMsg + "0 * X + 3 * Y / 3 - 12 = Z\n";
			strMsg = strMsg + "1 + Z * 100 * Y / 100 / 5 * X + 100 - 149 + 49 + Z + 12 + 100 = K\n";
			strMsg = strMsg + "\n问题请问 : K 的数值是多少?\n";
			strMsg = strMsg + "使用 ans <答案>\n";
			answer = "101";
			qn="M4";
			tell_object(me, strMsg);
			tell_object(me, NOR"请在这里回答\n"NOR);
			break;
		}

	case 5:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + " ****1**** \n";
			strMsg = strMsg + " *       * \n";
			strMsg = strMsg + " 2       3 \n";
			strMsg = strMsg + " *       * \n";
			strMsg = strMsg + " ****4*******8**** \n";
			strMsg = strMsg + " *       *       * \n";
			strMsg = strMsg + " 5       6       9 \n";
			strMsg = strMsg + " *       *       * \n";
			strMsg = strMsg + " ****7******10**** \n\n";
			strMsg = strMsg + "以上是某门派武功的攻击招术所转变出来的几何图形\n";
			strMsg = strMsg + "\n请问 : 要移动哪两边才可以产生四个同样的长方形?\n";
			strMsg = strMsg + "使用 ans <数字一> <数字二>    注意: 数字请从最小排到最大\n";
			
			answer = "5 7";
			qn="G5";
			tell_object(me, strMsg);
			tell_object(me, NOR"请在这里回答\n"NOR);
			break;
		}

	case 6:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + "         ****1**** \n";
			strMsg = strMsg + "         *       * \n";
			strMsg = strMsg + "         3       6 \n";
			strMsg = strMsg + "         *       * \n";
			strMsg = strMsg + " ****2****       * \n";
			strMsg = strMsg + " *       *       * \n";
			strMsg = strMsg + "12      13       16\n";
			strMsg = strMsg + " *       *       * \n";
			strMsg = strMsg + " *       ****5*******8***** \n";
			strMsg = strMsg + " *       *                *\n";
			strMsg = strMsg + "14       7                9\n";
			strMsg = strMsg + " *       *                *\n";
			strMsg = strMsg + " ***15******10******11*****\n";
			strMsg = strMsg + "以上是某门派武功的防守招术所转变出来的几何图形\n";
			strMsg = strMsg + "\n请问 : 要移动哪三边才可以产生六个正方形?\n";
			strMsg = strMsg + "使用 ans <数字一> <数字二> <数字三>    注意: 数字请从最小排到最大\n";
			answer = "8 9 11";
			qn="G6";
			tell_object(me, strMsg);
			tell_object(me, NOR"请在这里回答\n"NOR);
			break;
		}

	case 7:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + "****1****\n";
			strMsg = strMsg + "*       *\n";
			strMsg = strMsg + "2       3\n";
			strMsg = strMsg + "*       *\n";
			strMsg = strMsg + "****4****\n";
			strMsg = strMsg + "*       *\n";
			strMsg = strMsg + "5       6\n";
			strMsg = strMsg + "*       *\n";
			strMsg = strMsg + "****7*******8*******9****\n";
			strMsg = strMsg + "*       *       *       *\n";
			strMsg = strMsg + "10      11      12      13\n";
			strMsg = strMsg + "*       *       *       * \n";
			strMsg = strMsg + "***14******15******16**** \n";
			strMsg = strMsg + "以上是某门派武功的剑法所转变出来的几何图形\n";
			strMsg = strMsg + "\n请问 : 要移动哪四边才可以产生四个一样大个正方形?\n";
			strMsg = strMsg + "使用 ans <数字一> <数字二> <数字三> <数字四>    注意: 数字请从最小排到最大\n";
			answer = "5 6 8 15";
			qn="G7";
			tell_object(me, strMsg);
			tell_object(me, NOR"请在这里回答\n"NOR);
			break;
		}


	case 8:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + "****1*******2*******3****\n";
			strMsg = strMsg + "*       *       *       *\n";
			strMsg = strMsg + "4       5       6       7\n";
			strMsg = strMsg + "*       *       *       *\n";
			strMsg = strMsg + "****8*******9******10****\n";
			strMsg = strMsg + "*       *       *       *\n";
			strMsg = strMsg + "11      12      13      14\n";
			strMsg = strMsg + "*       *       *       *\n";
			strMsg = strMsg + "***15******16******17****\n";
			strMsg = strMsg + "*       *       *       *\n";
			strMsg = strMsg + "18      19      20      21\n";
			strMsg = strMsg + "*       *       *       *\n";
			strMsg = strMsg + "***22******23******24****\n";
			strMsg = strMsg + "以上是某门派武功的掌法所转变出来的几何图形\n";
			strMsg = strMsg + "\n请问 : 要移动哪四边才可以产生五个一样大个正方形?\n";
			strMsg = strMsg + "使用 ans <数字一> <数字二> <数字三> <数字四>    注意: 数字请从最小排到最大\n";
			answer = "2 11 14 23";
			qn="G8";
			tell_object(me, strMsg);
			tell_object(me, NOR"请在这里回答\n"NOR);
			break;
		}


	default:
		{
			strMsg = HIW"一个弟子快步走过来对着你说到：掌门人有问题想跟你讨论以下就是他要我问你的问题\n"NOR;
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r1+" * "+r2+" * "+r3+" * "+r4+" * "+r5+" *\n";
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r6+" *  1 *  4 *  7 * "+r16+" *\n";
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r7+" *  2 *  5 *  8 * "+r15+" *\n";
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r8+" *  3 *  6 *  9 * "+r14+" *\n";
			strMsg = strMsg + "**************************\n";
			strMsg = strMsg + "* "+r9+" * "+r10+" * "+r11+" * "+r12+" * "+r3+" *\n";
			strMsg = strMsg + "**************************\n";

			answer = "2t"+r10+" "+r10+"t"+r16+" "+r16+"t1 1t9";

			tell_object(me, strMsg);
			tell_object(me, HIW"以上是某门派的阵形，如果要破解必须在四条线内将一到九全部碰到\n一但完成这个阵就不攻自破了，你有六十秒的时间思考"NOR);
			tell_object(me, NOR"\n回答方法使用点对点方式，如果从一碰到三然后三碰到九然后九碰到七最后七到一，指令为 ans 1t3 3t9 9t7 7t1，\n"NOR);
			qn="G1";
		}
	}

	me->start_busy(3);
	npc = new("/family_job/ansnpc");
	npc->set("aid", me->query("id"));
	npc->move(environment(me));
	npc->set("correctans", answer);

	CHANNEL_D->do_channel(this_object(), "sys", sprintf("工作目标: %s(%s)  工作NPC: %s  工作型态: 智慧型问题  题目编号: %s", me->query("name"), me->query("id"), npc->query("name"), qn));
	final_count();
	return;
}
	

//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//**********************    Menpai KILLER Star Here  **************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
void menpai_killer(object me, string strName, string strId, string strFName, int intExp)
{
	object npc, pid, *list;
	mapping hp_status, skill_status, map_status, prepare_status;
	mapping my;
    mapping skill_statusb;
	int i, temp, myexp, mylvl, k, count, point;
    int j, total, looptime, m;
    string *sname, *mname, *pname, pkid;
    string *snameb;
	string strMsg;


	strMsg = HIR+"$n说到：你这个不要脸的家伙今天让我送你上路\n"+NOR;
	npc = new("/family_job/heyiren");
        
        list = users();
        total = sizeof(list);

        m = 0;

        for(m=0; m!=1; m) 
        {
                j = random(total);
                list[j]->short(1);
                pid = list[j];

                if(pid->query("combat_exp") > 500000)
                {
                        m = 1;
                }

                if(looptime > 10)
                {
                        m = 1;
                        pid = me;                       
                }

                looptime = looptime + 1;
        }



        if (mapp(skill_status = npc->query_skills()))
        {
                skill_status = npc->query_skills();
                sname = keys(skill_status);

                temp = sizeof(skill_status);
                for (i = 0; i < temp; i++)
                        npc->delete_skill(sname[i]);
        }

        if (mapp(skill_status = pid->query_skills()))
        {
                skill_status = pid->query_skills();
                sname = keys(skill_status);

                for (i = 0; i < sizeof(skill_status); i++)
                        npc->set_skill(sname[i], skill_status[sname[i]]);
        }
        
        if (mapp(map_status = npc->query_skill_map()))
        {
                mname = keys(map_status);

                temp = sizeof(map_status);
                for (i = 0; i < temp; i++)
                        npc->map_skill(mname[i]);
        }

        if (mapp(map_status = pid->query_skill_map()))
        {
                mname = keys(map_status);

                for(i = 0; i < sizeof(map_status); i++)
                        npc->map_skill(mname[i], map_status[mname[i]]);
        }

        if (mapp(prepare_status = npc->query_skill_prepare()))
        {
                pname = keys(prepare_status);

                temp = sizeof(prepare_status);
                for(i = 0; i < temp; i++)
                        npc->prepare_skill(pname[i]);
        }

        if (mapp(prepare_status = pid->query_skill_prepare()))
        {
                pname = keys(prepare_status);

                for(i = 0; i < sizeof(prepare_status); i++)
                        npc->prepare_skill(pname[i], prepare_status[pname[i]]);
        }


        hp_status = me->query_entire_dbase();
        my = npc->query_entire_dbase();

        my["str"] = hp_status["str"];
        my["int"] = hp_status["int"];
        my["con"] = hp_status["con"];
        my["dex"] = hp_status["dex"];

        my["max_qi"]     = hp_status["max_qi"];
        my["eff_qi"]     = hp_status["eff_qi"];
        my["qi"]         = hp_status["qi"];
        my["max_jing"]   = hp_status["max_jing"];
        my["eff_jing"]   = hp_status["eff_jing"];
        my["max_jingli"]   = hp_status["max_jingli"];
        my["eff_jingli"]   = hp_status["eff_jingli"];
        my["jingli"]       = hp_status["jingli"];
        my["jing"]       = hp_status["jing"];
        my["max_neili"]  = hp_status["max_neili"];
        my["neili"]      = hp_status["neili"];
        my["jiali"]      = hp_status["jiali"];
        my["combat_exp"] = hp_status["combat_exp"];

                
                
                npc->reset_action();
                myexp = npc->query("combat_exp");

                if (myexp>50000) myexp = 50000;
                myexp *= 1000;
                mylvl = to_int(pow(myexp*10,0.33333)-10);
                
                myexp = npc->query("combat_exp");
                myexp /= 1000;

                if (myexp>50000) myexp = 50000;
        myexp *= 1000;
        mylvl = to_int(pow(myexp*10,0.33333)+1);

        if ( mapp(skill_statusb = npc->query_skills()) ) {
                skill_statusb = npc->query_skills();
                snameb = keys(skill_statusb);
                count = sizeof(skill_statusb);

                for(k=0; k<sizeof(skill_statusb); k++) 
                                {
                        npc->set_skill(snameb[k],mylvl);
                }
        }

        npc->set("combat_exp",myexp);

		npc->set_skill("poison", 100);
		npc->set_skill("qianzhu-wandu", 70);


		pkid = me->query("id");
        npc->set_temp("pkid", pkid);
		npc->move(environment(me));
		strMsg = strMsg + HIW + vermsg + NOR;
		message_vision(strMsg, me, npc);
		message_vision(HIG"突然$n冲了过来使出天地无双将你突然震住\n"NOR, me, npc);
		me->start_busy(2);


		switch(strFName)
        {
        case "武当派":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        case "少林派":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 50);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        case "丐帮":
                {
                        npc->set_temp("apply/dodge", 50);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 85);
                        break;
                }
        case "星宿派":
                {
                        npc->set_temp("apply/dodge", 150);
						npc->set_temp("apply/damage", 150);
						npc->set_temp("apply/speed", 150);
						npc->set_temp("apply/armor", 175);
                        break;
                }
        case "峨嵋派":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        case "大理段家":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        case "古墓派":
                {
                        npc->set_temp("apply/dodge", 150);
						npc->set_temp("apply/damage", 135);
						npc->set_temp("apply/speed", 100);
						npc->set_temp("apply/armor", 155);
                        break;
                }
        case "白驼山":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 80);
						npc->set_temp("apply/speed", 80);
						npc->set_temp("apply/armor", 125);
                        break;
                }
        case "华山派":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 30);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        case "雪山派":
                {
                        npc->set_temp("apply/dodge", 150);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        case "桃花岛":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        case "全真教":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        case "昆仑派":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        default:
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 55);
                }
        }

		CHANNEL_D->do_channel(this_object(), "sys", sprintf("杀手目标: %s(%s)  工作NPC: %s  工作型态: 主动刺杀行动", me->query("name"), me->query("id"), npc->query("name")));
		final_count();
		return;
}


//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//**********************    Menpai Job Star Here  *****************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************

void detect_menpai(object me, string strName, string strId, string strFName, int intExp)
{
        string strMenpai, strMsg, strDir, strCPlace;
        int intRnd;

        switch(strFName)
        {
        case "武当派":
                {
                        strMenpai = "wd";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "少林派":
                {
                        strMenpai = "sl";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "丐帮":
                {
                        strMenpai = "gb";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "星宿派":
                {
                        strMenpai = "xx";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "峨嵋派":
                {
                        strMenpai = "em";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "大理段家":
                {
                        strMenpai = "dl";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "古墓派":
                {
                        strMenpai = "gm";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "白驼山":
                {
                        strMenpai = "bt";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "华山派":
                {
                        strMenpai = "hs";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "雪山派":
                {
                        strMenpai = "xs";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "桃花岛":
                {
                        strMenpai = "th";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "全真教":
                {
                        strMenpai = "qz";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        case "昆仑派":
                {
                        strMenpai = "kl";
                        strMsg = HIW+"一个"+strFName+"弟子快步走了过来\n"+strFName+"弟子对着$N说到："+NOR;
                        break;
                }
        default:
                {
                        write("错误资讯 "+strFName+"\n");
                        get_player();
                        return;
                }
        }

        switch(random(13))
        {
        case 0:
                {
                        strDir = "baituo";
                        strCPlace = "白驼";
                        break;
                }
        case 1:
                {
                        strDir = "beijing";
                        strCPlace = "北京";
                        break;
                }
        case 2:
                {
                        strDir = "changan";
                        strCPlace = "长安";
                        break;
                }
        case 3:
                {
                        strDir = "changbai";
                        strCPlace = "长白";
                        break;
                }
        case 4:
                {
                        strDir = "city";
                        strCPlace = "扬洲城";
                        break;
                }
        case 5:
                {
                        //strDir = "taohua";
                        //strCPlace = "桃花";
						strDir = "wuguan";
						strCPlace = "武馆";
                        break;
                }
        case 6:
                {
                        strDir = "gumu";
                        strCPlace = "古墓";
                        break;
                }
        case 7:
                {
                        strDir = "huashan";
                        strCPlace = "华山";
                        break;
                }
        case 8:
                {
                        strDir = "wudang";
                        strCPlace = "武当";
                        break;
                }
        case 9:
                {
                        strDir = "xingxiu";
                        strCPlace = "星宿";
                        break;
                }
        case 10:
                {
                        strDir = "xixia";
                        strCPlace = "西夏";
                        break;
                }
		case 11:
				{
						strDir = "emei";
						strCPlace = "峨嵋";
						break;
				}
		case 12:
				{
						strDir = "xueshan";
						strCPlace = "雪山";
						break;
				}
        default:
                {
                        strDir = "taishan";
                        strCPlace = "泰山";
                        break;
                }
        }

        strDir = "/d/"+strDir+"/";

        create_path(me, strName, strId, strFName, intExp, strMenpai, strMsg, strDir, strCPlace);
        return;
}

void create_path(object me, string strName, string strId, string strFName, int intExp, string strMenpai, string strMsg, string strDir, string strCPlace)
{
        string *dir, *dirx, roomx;
        object npc, room;
        int i, j;

                dirx = get_dir(strDir);
        
                j = random(sizeof(dirx) - 1);
				roomx = strDir+dirx[j];
                write(HIC"\n现在的随机房间是"+roomx+"。\n"NOR);

        if ( !(room = find_object(roomx)) )
                {
                        room = load_object(roomx);
                }

                do_set_skill(me, room, strMsg, strDir, strCPlace, roomx);

        return;
}


void do_set_skill(object me, object room, string strMsg, string strDir, string strCPlace, string roomx)
{
        object ob, npc;
        string pkid;
        write("skill_set\n");

        npc = new("/family_job/heyiren");
        if (!objectp(npc))
        {
                write(HIC"\nNPC error!\n");
                final_count();
                return;
        }

        copy_skill(npc, me);
        pkid = me->query("id");
        npc->set_temp("pkid", pkid);
        npc->move(room);

        create_msg(me, room, strMsg, strDir, npc, strCPlace);
        return;
}

private int copy_skill(object npc, object me)
{
        object pid, *list;
        mapping hp_status, skill_status, map_status, prepare_status;
		mapping my;
        mapping skill_statusb;
        string *sname, *mname, *pname;
        string *snameb;
    int i, temp, myexp, mylvl, k, count, point;
        int j, total, looptime, m;
        
        list = users();
        total = sizeof(list);

        m = 0;

        for(m=0; m!=1; m) 
        {
                j = random(total);
                list[j]->short(1);
                pid = list[j];

                if(pid->query("combat_exp") > 500000)
                {
                        m = 1;
                }

                if(looptime > 10)
                {
                        m = 1;
                        pid = me;                       
                }

                looptime = looptime + 1;
        }



        if (mapp(skill_status = npc->query_skills()))
        {
                skill_status = npc->query_skills();
                sname = keys(skill_status);

                temp = sizeof(skill_status);
                for (i = 0; i < temp; i++)
                        npc->delete_skill(sname[i]);
        }

        if (mapp(skill_status = pid->query_skills()))
        {
                skill_status = pid->query_skills();
                sname = keys(skill_status);

                for (i = 0; i < sizeof(skill_status); i++)
                        npc->set_skill(sname[i], skill_status[sname[i]]);
        }
        
        if (mapp(map_status = npc->query_skill_map()))
        {
                mname = keys(map_status);

                temp = sizeof(map_status);
                for (i = 0; i < temp; i++)
                        npc->map_skill(mname[i]);
        }

        if (mapp(map_status = pid->query_skill_map()))
        {
                mname = keys(map_status);

                for(i = 0; i < sizeof(map_status); i++)
                        npc->map_skill(mname[i], map_status[mname[i]]);
        }

        if (mapp(prepare_status = npc->query_skill_prepare()))
        {
                pname = keys(prepare_status);

                temp = sizeof(prepare_status);
                for(i = 0; i < temp; i++)
                        npc->prepare_skill(pname[i]);
        }

        if (mapp(prepare_status = pid->query_skill_prepare()))
        {
                pname = keys(prepare_status);

                for(i = 0; i < sizeof(prepare_status); i++)
                        npc->prepare_skill(pname[i], prepare_status[pname[i]]);
        }


        hp_status = me->query_entire_dbase();
        my = npc->query_entire_dbase();

        my["str"] = hp_status["str"];
        my["int"] = hp_status["int"];
        my["con"] = hp_status["con"];
        my["dex"] = hp_status["dex"];

        my["max_qi"]     = hp_status["max_qi"];
        my["eff_qi"]     = hp_status["eff_qi"];
        my["qi"]         = hp_status["qi"];
        my["max_jing"]   = hp_status["max_jing"];
        my["eff_jing"]   = hp_status["eff_jing"];
        my["max_jingli"]   = hp_status["max_jingli"];
        my["eff_jingli"]   = hp_status["eff_jingli"];
        my["jingli"]       = hp_status["jingli"];
        my["jing"]       = hp_status["jing"];
        my["max_neili"]  = hp_status["max_neili"];
        my["neili"]      = hp_status["neili"];
        my["jiali"]      = hp_status["jiali"];
        my["combat_exp"] = hp_status["combat_exp"];

                
                
                npc->reset_action();
                myexp = npc->query("combat_exp");

                if (myexp>50000) myexp = 50000;
                myexp *= 1000;
                mylvl = to_int(pow(myexp*10,0.33333)-10);
                
                myexp = npc->query("combat_exp");
                myexp /= 1000;

                if (myexp>50000) myexp = 50000;
        myexp *= 1000;
        mylvl = to_int(pow(myexp*10,0.33333)+1);

        if ( mapp(skill_statusb = npc->query_skills()) ) {
                skill_statusb = npc->query_skills();
                snameb = keys(skill_statusb);
                count = sizeof(skill_statusb);

                for(k=0; k<sizeof(skill_statusb); k++) 
                                {
                        npc->set_skill(snameb[k],mylvl);
                }
        }

        npc->set("combat_exp",myexp);

        return 1;
}


void create_msg(object me, object room, string strMsg, string strDir, object npc, string strCPlace)
{
        if(me==0)
        {
                write(HIR"error : me = 0\nSELF RESTART\n"NOR);
                get_player();
                return;
        }

        if(room==0)
        {
                write(HIR"error : room = 0\nSELF RESTART\n"NOR);
                get_player();
                return;
        }

        //strMsg = strMsg + HIW"掌门人要$N去" + room->query("short") + "位于"+strCPlace+"把" + npc->query("name") + "杀掉\n\n(V 4.0 正式版)\n"NOR;
		strMsg = strMsg + HIW"掌门人要$N去" + room->query("short") + "位于"+strCPlace+"把" + npc->query("name") + "杀掉" + HIW + vermsg + NOR;
        CHANNEL_D->do_channel(this_object(), "sys", sprintf("工作玩家: %s(%s)  工作NPC: %s  工作地点: %s位于%s。", me->query("name"), me->query("id"), npc->query("name"), room->query("short"), strCPlace));
        write(strMsg);
        message_vision(strMsg, me);
        final_count();
        return;
}


void final_count()
{
        string ctime;
        int looptime;
        
        if(query("looptime"))
        {
                ctime = query("looptime");
                looptime = atoi(ctime);
        }
        
        else
        {
                looptime = 60;
        }


        remove_call_out("do_reset");
        call_out("get_player", looptime);
        return;
}
