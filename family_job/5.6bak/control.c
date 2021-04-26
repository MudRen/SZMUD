// control.c
// CODE BY SCATTER
#include <ansi.h>
inherit ROOM;

string vermsg="\n\n(V 5.6B ��ʽ��)\n";
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
        set("short", HIY"���ɹ���������"NOR);
        set("channel_id", "��������ϵͳ(AAJ)");
        set("long", "��������\n���� (start_job)\n�ر� (stop_job)\n����һ�ι��� (give_job)\n�趨����ʱ�� (set_time <ʱ��>)\n\n");

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
                write("��ʽ����\n");
                return 1;
        }

        set("looptime", arg);
		CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIR"��ؼ�ͻȻ�ζ���һ�£�˲�����ǴӶ����Ŀ��л��˹�ȥ��"));
        CHANNEL_D->do_channel(this_object(), "sys", sprintf("���Ź���ʱ���趨��Ϊ %s �롣", arg));
        return 1;
}



int stop_job(string arg)
{
        if(!query_temp("job_enable"))
        {
                write("����ϵͳ�Ա������ǹرյ�\n");
                return 1;
        }
        CHANNEL_D->do_channel(this_object(), "sys", sprintf("�Զ��ַ�����ϵͳ�رա�"));
		CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIR"����еĲʺ���������ʧ�����������в���������"));
        delete_temp("job_enable");
        return 1;
}

int start_job(string arg)
{
        if(query_temp("job_enable"))
        {
                write("����ϵͳ������\n");
                return 1;
        }

        CHANNEL_D->do_channel(this_object(), "sys", sprintf("�Զ��ַ�����ϵͳ������"));
		CHANNEL_D->do_channel(this_object(), "rumor", sprintf(HIR"ͻȻ��ؼ���һ��˵��˵����ѹ��������������ĳ�����һ���ʺ磬���������в���������"));
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
                write("������ֹ\n");
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
			strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
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
			tell_object(me, HIW"������ĳ���ɵ����Σ����Ҫ�ƽ�������������ڽ�һ����ȫ������\nһ����������Ͳ��������ˣ�������ʮ���ʱ��˼��"NOR);
			tell_object(me, NOR"\n�ش𷽷�ʹ�õ�Ե㷽ʽ�������һ������Ȼ����������Ȼ�������������ߵ�һ��ָ��Ϊ ans 1t3 3t9 9t7 7t1��\n"NOR);
			tell_object(me, NOR"��������ش� (��ʼֱ�� 2)\n"NOR);
			qn="G1";
			break;
		}
	case 1:
		{
			strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
			strMsg = strMsg + "һ�򣬶��ɣ����������飬��ƽ����ˣ�����÷����ĺ����ѣ���񳤴���ˣ�\n";
			strMsg = strMsg + "���Ե���������ϰ壬��ʦ������ϰ壬�ξƾ����̺͹�˾ְԱ��\n\n";
			strMsg = strMsg + "1.������ϰ岻��������Ҳ�������顣\n";
			strMsg = strMsg + "2.�ξƾ����̲������飬Ҳ����һ��\n";
			strMsg = strMsg + "3.���⣬��������ƽס��ͬһ����Ԣ�������ǹ�˾ְԱ�ļҡ�\n";
			strMsg = strMsg + "4.����Ȣ��ʦ��Ů��ʱ�����������ǵ�ý�ˡ�\n";
			strMsg = strMsg + "5.һ��������п�ʱ���ͺ�����ϰ壬������ϰ���ơ�\n";
			strMsg = strMsg + "6.���ң�ÿ��ʮ�죬�������ƽһ��Ҫ�������޸�����\n";
			strMsg = strMsg + "7.���ǣ���˾ְԱ��һ���Լ��κ��ӣ�������������ȥ��\n\n";
			strMsg = strMsg + "���� : �뽫������˵�ְҵ����˳��д�������ÿո����ֿ�\n";
			strMsg = strMsg + "(ʹ�� ans <һ���ְҵ> <���ɵ�ְҵ> <������ְҵ> <�����ְҵ> <��ƽ��ְҵ>\n";
			tell_object(me, strMsg);
			tell_object(me, NOR"��������ش�\n"NOR);
			answer = "��ʦ ��˾ְԱ �ξƾ����� ����ϰ� ������ϰ�";
			qn="L2";
			break;
		}
	case 2:
		{
			strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
			strMsg = strMsg + "(4 * 2 / 4) * (4 * 2 / 4) + 4 - 4 * 2 = X\n";
			strMsg = strMsg + "X + 3 + 7 - 4 / 2 - 8 = Y\n";
			strMsg = strMsg + "0 * X + 3 * Y / 3 - 12 = Z\n";
			strMsg = strMsg + "Z * 100 * Y / 100 / 5 * X + 100 - 149 + 49 + Z + 100 = K\n";
			strMsg = strMsg + "\n�������� : K ����ֵ�Ƕ���?\n";
			strMsg = strMsg + "ʹ�� ans <��>\n";
			answer = "88";
			qn="M3";
			tell_object(me, strMsg);
			tell_object(me, NOR"��������ش�\n"NOR);
			break;
		}
	case 4:
		{
			strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
			strMsg = strMsg + "(4 * 2 / 4) * (4 * 2 / 4) + 4 - 4 * 2 = X\n";
			strMsg = strMsg + "X + 3 + 7 - 4 / 2 - 8 = Y\n";
			strMsg = strMsg + "0 * X + 3 * Y / 3 - 12 = Z\n";
			strMsg = strMsg + "1 + Z * 100 * Y / 100 / 5 * X + 100 - 149 + 49 + Z + 12 + 100 = K\n";
			strMsg = strMsg + "\n�������� : K ����ֵ�Ƕ���?\n";
			strMsg = strMsg + "ʹ�� ans <��>\n";
			answer = "101";
			qn="M4";
			tell_object(me, strMsg);
			tell_object(me, NOR"��������ش�\n"NOR);
			break;
		}

	case 5:
		{
			strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
			strMsg = strMsg + " ****1**** \n";
			strMsg = strMsg + " *       * \n";
			strMsg = strMsg + " 2       3 \n";
			strMsg = strMsg + " *       * \n";
			strMsg = strMsg + " ****4*******8**** \n";
			strMsg = strMsg + " *       *       * \n";
			strMsg = strMsg + " 5       6       9 \n";
			strMsg = strMsg + " *       *       * \n";
			strMsg = strMsg + " ****7******10**** \n\n";
			strMsg = strMsg + "������ĳ�����书�Ĺ���������ת������ļ���ͼ��\n";
			strMsg = strMsg + "\n���� : Ҫ�ƶ������߲ſ��Բ����ĸ�ͬ���ĳ�����?\n";
			strMsg = strMsg + "ʹ�� ans <����һ> <���ֶ�>    ע��: ���������С�ŵ����\n";
			
			answer = "5 7";
			qn="G5";
			tell_object(me, strMsg);
			tell_object(me, NOR"��������ش�\n"NOR);
			break;
		}

	case 6:
		{
			strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
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
			strMsg = strMsg + "������ĳ�����书�ķ���������ת������ļ���ͼ��\n";
			strMsg = strMsg + "\n���� : Ҫ�ƶ������߲ſ��Բ�������������?\n";
			strMsg = strMsg + "ʹ�� ans <����һ> <���ֶ�> <������>    ע��: ���������С�ŵ����\n";
			answer = "8 9 11";
			qn="G6";
			tell_object(me, strMsg);
			tell_object(me, NOR"��������ش�\n"NOR);
			break;
		}

	case 7:
		{
			strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
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
			strMsg = strMsg + "������ĳ�����书�Ľ�����ת������ļ���ͼ��\n";
			strMsg = strMsg + "\n���� : Ҫ�ƶ����ı߲ſ��Բ����ĸ�һ�����������?\n";
			strMsg = strMsg + "ʹ�� ans <����һ> <���ֶ�> <������> <������>    ע��: ���������С�ŵ����\n";
			answer = "5 6 8 15";
			qn="G7";
			tell_object(me, strMsg);
			tell_object(me, NOR"��������ش�\n"NOR);
			break;
		}


	case 8:
		{
			strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
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
			strMsg = strMsg + "������ĳ�����书���Ʒ���ת������ļ���ͼ��\n";
			strMsg = strMsg + "\n���� : Ҫ�ƶ����ı߲ſ��Բ������һ�����������?\n";
			strMsg = strMsg + "ʹ�� ans <����һ> <���ֶ�> <������> <������>    ע��: ���������С�ŵ����\n";
			answer = "2 11 14 23";
			qn="G8";
			tell_object(me, strMsg);
			tell_object(me, NOR"��������ش�\n"NOR);
			break;
		}


	default:
		{
			strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
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
			tell_object(me, HIW"������ĳ���ɵ����Σ����Ҫ�ƽ�������������ڽ�һ����ȫ������\nһ����������Ͳ��������ˣ�������ʮ���ʱ��˼��"NOR);
			tell_object(me, NOR"\n�ش𷽷�ʹ�õ�Ե㷽ʽ�������һ������Ȼ����������Ȼ�������������ߵ�һ��ָ��Ϊ ans 1t3 3t9 9t7 7t1��\n"NOR);
			qn="G1";
		}
	}

	me->start_busy(3);
	npc = new("/family_job/ansnpc");
	npc->set("aid", me->query("id"));
	npc->move(environment(me));
	npc->set("correctans", answer);

	CHANNEL_D->do_channel(this_object(), "sys", sprintf("����Ŀ��: %s(%s)  ����NPC: %s  ������̬: �ǻ�������  ��Ŀ���: %s", me->query("name"), me->query("id"), npc->query("name"), qn));
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


	strMsg = HIR+"$n˵�����������Ҫ���ļһ��������������·\n"+NOR;
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
		message_vision(HIG"ͻȻ$n���˹���ʹ�������˫����ͻȻ��ס\n"NOR, me, npc);
		me->start_busy(2);


		switch(strFName)
        {
        case "�䵱��":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        case "������":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 50);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        case "ؤ��":
                {
                        npc->set_temp("apply/dodge", 50);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 85);
                        break;
                }
        case "������":
                {
                        npc->set_temp("apply/dodge", 150);
						npc->set_temp("apply/damage", 150);
						npc->set_temp("apply/speed", 150);
						npc->set_temp("apply/armor", 175);
                        break;
                }
        case "������":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        case "����μ�":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        case "��Ĺ��":
                {
                        npc->set_temp("apply/dodge", 150);
						npc->set_temp("apply/damage", 135);
						npc->set_temp("apply/speed", 100);
						npc->set_temp("apply/armor", 155);
                        break;
                }
        case "����ɽ":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 80);
						npc->set_temp("apply/speed", 80);
						npc->set_temp("apply/armor", 125);
                        break;
                }
        case "��ɽ��":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 30);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        case "ѩɽ��":
                {
                        npc->set_temp("apply/dodge", 150);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        case "�һ���":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        case "ȫ���":
                {
                        npc->set_temp("apply/dodge", 100);
						npc->set_temp("apply/damage", 40);
						npc->set_temp("apply/speed", 10);
						npc->set_temp("apply/armor", 55);
                        break;
                }
        case "������":
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

		CHANNEL_D->do_channel(this_object(), "sys", sprintf("ɱ��Ŀ��: %s(%s)  ����NPC: %s  ������̬: ������ɱ�ж�", me->query("name"), me->query("id"), npc->query("name")));
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
        case "�䵱��":
                {
                        strMenpai = "wd";
                        strMsg = HIW+"һ��"+strFName+"���ӿ첽���˹���\n"+strFName+"���Ӷ���$N˵����"+NOR;
                        break;
                }
        case "������":
                {
                        strMenpai = "sl";
                        strMsg = HIW+"һ��"+strFName+"���ӿ첽���˹���\n"+strFName+"���Ӷ���$N˵����"+NOR;
                        break;
                }
        case "ؤ��":
                {
                        strMenpai = "gb";
                        strMsg = HIW+"һ��"+strFName+"���ӿ첽���˹���\n"+strFName+"���Ӷ���$N˵����"+NOR;
                        break;
                }
        case "������":
                {
                        strMenpai = "xx";
                        strMsg = HIW+"һ��"+strFName+"���ӿ첽���˹���\n"+strFName+"���Ӷ���$N˵����"+NOR;
                        break;
                }
        case "������":
                {
                        strMenpai = "em";
                        strMsg = HIW+"һ��"+strFName+"���ӿ첽���˹���\n"+strFName+"���Ӷ���$N˵����"+NOR;
                        break;
                }
        case "����μ�":
                {
                        strMenpai = "dl";
                        strMsg = HIW+"һ��"+strFName+"���ӿ첽���˹���\n"+strFName+"���Ӷ���$N˵����"+NOR;
                        break;
                }
        case "��Ĺ��":
                {
                        strMenpai = "gm";
                        strMsg = HIW+"һ��"+strFName+"���ӿ첽���˹���\n"+strFName+"���Ӷ���$N˵����"+NOR;
                        break;
                }
        case "����ɽ":
                {
                        strMenpai = "bt";
                        strMsg = HIW+"һ��"+strFName+"���ӿ첽���˹���\n"+strFName+"���Ӷ���$N˵����"+NOR;
                        break;
                }
        case "��ɽ��":
                {
                        strMenpai = "hs";
                        strMsg = HIW+"һ��"+strFName+"���ӿ첽���˹���\n"+strFName+"���Ӷ���$N˵����"+NOR;
                        break;
                }
        case "ѩɽ��":
                {
                        strMenpai = "xs";
                        strMsg = HIW+"һ��"+strFName+"���ӿ첽���˹���\n"+strFName+"���Ӷ���$N˵����"+NOR;
                        break;
                }
        case "�һ���":
                {
                        strMenpai = "th";
                        strMsg = HIW+"һ��"+strFName+"���ӿ첽���˹���\n"+strFName+"���Ӷ���$N˵����"+NOR;
                        break;
                }
        case "ȫ���":
                {
                        strMenpai = "qz";
                        strMsg = HIW+"һ��"+strFName+"���ӿ첽���˹���\n"+strFName+"���Ӷ���$N˵����"+NOR;
                        break;
                }
        case "������":
                {
                        strMenpai = "kl";
                        strMsg = HIW+"һ��"+strFName+"���ӿ첽���˹���\n"+strFName+"���Ӷ���$N˵����"+NOR;
                        break;
                }
        default:
                {
                        write("������Ѷ "+strFName+"\n");
                        get_player();
                        return;
                }
        }

        switch(random(13))
        {
        case 0:
                {
                        strDir = "baituo";
                        strCPlace = "����";
                        break;
                }
        case 1:
                {
                        strDir = "beijing";
                        strCPlace = "����";
                        break;
                }
        case 2:
                {
                        strDir = "changan";
                        strCPlace = "����";
                        break;
                }
        case 3:
                {
                        strDir = "changbai";
                        strCPlace = "����";
                        break;
                }
        case 4:
                {
                        strDir = "city";
                        strCPlace = "���޳�";
                        break;
                }
        case 5:
                {
                        //strDir = "taohua";
                        //strCPlace = "�һ�";
						strDir = "wuguan";
						strCPlace = "���";
                        break;
                }
        case 6:
                {
                        strDir = "gumu";
                        strCPlace = "��Ĺ";
                        break;
                }
        case 7:
                {
                        strDir = "huashan";
                        strCPlace = "��ɽ";
                        break;
                }
        case 8:
                {
                        strDir = "wudang";
                        strCPlace = "�䵱";
                        break;
                }
        case 9:
                {
                        strDir = "xingxiu";
                        strCPlace = "����";
                        break;
                }
        case 10:
                {
                        strDir = "xixia";
                        strCPlace = "����";
                        break;
                }
		case 11:
				{
						strDir = "emei";
						strCPlace = "����";
						break;
				}
		case 12:
				{
						strDir = "xueshan";
						strCPlace = "ѩɽ";
						break;
				}
        default:
                {
                        strDir = "taishan";
                        strCPlace = "̩ɽ";
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
                write(HIC"\n���ڵ����������"+roomx+"��\n"NOR);

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

        //strMsg = strMsg + HIW"������Ҫ$Nȥ" + room->query("short") + "λ��"+strCPlace+"��" + npc->query("name") + "ɱ��\n\n(V 4.0 ��ʽ��)\n"NOR;
		strMsg = strMsg + HIW"������Ҫ$Nȥ" + room->query("short") + "λ��"+strCPlace+"��" + npc->query("name") + "ɱ��" + HIW + vermsg + NOR;
        CHANNEL_D->do_channel(this_object(), "sys", sprintf("�������: %s(%s)  ����NPC: %s  �����ص�: %sλ��%s��", me->query("name"), me->query("id"), npc->query("name"), room->query("short"), strCPlace));
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
