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
        if(room==0)
        {
                write(HIR"error : room = 0\nSELF RESTART\n"NOR);
        	create_path(me, strName, strId, strFName, intExp, strMenpai, strMsg, strDir, strCPlace);
                return ;
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
                return;
        }

        //strMsg = strMsg + HIW"������Ҫ$Nȥ" + room->query("short") + "λ��"+strCPlace+"��" + npc->query("name") + "ɱ��\n\n(V 4.0 ��ʽ��)\n"NOR;
		strMsg = strMsg + HIW"������Ҫ$Nȥ" + room->query("short") + "λ��"+strCPlace+"��" + npc->query("name") + "ɱ��" + HIW + vermsg + NOR;
        CHANNEL_D->do_channel(this_object(), "sys", sprintf("�������: %s(%s)  ����NPC: %s  �����ص�: %sλ��%s��", me->query("name"), me->query("id"), npc->query("name"), room->query("short"), strCPlace));
        write(strMsg);
        message_vision(strMsg, me);
        return;
}
