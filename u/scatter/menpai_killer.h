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


		//TEMP SETTING DATA
                npc->set_skill("poison", 100);
                npc->set_skill("qianzhu-wandu", 70);
				npc->set_skill("longzhua-gong", 100);
		//END OF SETTING DATA


                pkid = me->query("id");
        npc->set_temp("pkid", pkid);
                npc->move(environment(me));


                strMsg = strMsg + HIW + vermsg + NOR;
                message_vision(strMsg, me, npc);
                message_vision(HIG"ͻȻ$n���˹���ʹ�������˫��$NͻȻ��ס\n"NOR, me, npc);
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
                return;
}