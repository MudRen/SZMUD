int do_check_user(object ob, string strMenpai) 
{
    string strSwitch;

    if(ob->query("family/family_name") != strMenpai)
    {
        return 0;
    }

    if(ob->query("combat_exp") < 100000)
    {
        return 0;
    }

    if(!ob->query("env/family_job"))
    {
        return 0;
    
    }
    if(environment(ob)->query("no_fight"))
    {
        return 0;
    }
    return 1;
}


void get_player()
{
    object me, *players;
    string strName, strId, strFName, strMenpai, *MenpaiList;
        string strJobMsg;
    int i, j, total, intExp, count;


        switch(random(7))
        {
        case 0:
                {
                        strJobMsg = "����";
                        break;
                }
        case 1:
                {
                        strJobMsg = "����";
                        break;
                }
        case 2:
                {
                        strJobMsg = "�Ϸ�";
                        break;
                }
        case 3:
                {
                        strJobMsg = "����";
                        break;
                }
        case 4:
                {
                        strJobMsg = "���Ϸ�";
                        break;
                }
        case 5:
                {
                        strJobMsg = "������";
                        break;
                }
        case 6:
                {
                        strJobMsg = "���Ϸ�";
                        break;
                }
        case 7:
                {
                        strJobMsg = "������";
                        break;
                }
        }

        strJobMsg = strJobMsg + "�����������";

        switch(random(4))
        {
        case 0:
                {
                        strJobMsg = strJobMsg + "��������";
                        break;
                }
        case 1:
                {
                        strJobMsg = strJobMsg + "��������";
                        break;
                }
        case 2:
                {
                        strJobMsg = strJobMsg + "��ɺ�ɫ";
                        break;
                }
        case 3:
                {
                        strJobMsg = strJobMsg + "����������";
                        break;
                }
        case 4:
                {
                        strJobMsg = strJobMsg + "������һ������";
                        break;
                }
        }

        strJobMsg = strJobMsg + "���ⰵʾ��һ����ɱ����չ����";


        switch(random(5))
        {
        case 0:
                {
                        strJobMsg = HIR + strJobMsg;
                        break;
                }
        case 1:
                {
                        strJobMsg = HIC + strJobMsg;
                        break;
                }
        case 2:
                {
                        strJobMsg = HIB + strJobMsg;
                        break;
                }
        case 4:
                {
                        strJobMsg = HIG + strJobMsg;
                        break;
                }
        case 5:
                {
                        strJobMsg = HIW + strJobMsg;
                        break;
                }
        }

        CHANNEL_D->do_channel(this_object(), "rumor", sprintf(strJobMsg));
                
        /*
        if(random(100) > 90)
        {
                write("mark1\n");
                mplayer_get_user();
        }
        else
        {
        */

                MenpaiList = ({"�䵱��","������","ؤ��","������","������","����μ�","��Ĺ��","����ɽ","��ɽ��","ѩɽ��","�һ���","ȫ���","������"});
                for(i=0;i<sizeof(MenpaiList);i++)
                {
                        write("���ڷ���"+MenpaiList[i]+"�Ĺ���\n");
                        players = filter_array(users(), "do_check_user", this_object(), MenpaiList[i]);
                        if(!query("job_enable"))
                        {
                                write("���ɹ�����ֹ\n");
                                return;
                        }
                        if(!sizeof(players))
                        {
                                write("����"+MenpaiList[i]+"�Ĺ���û����������\n");
                                continue;
                        }
                        else
                        {
                                total = sizeof(players);
                                j = random(total);
                                me = players[j];
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
                                                if ( (int)me->query( "menpai/gxd" ) > 200 )
                                                        menpai_question(me, strName, strId, strFName, intExp);
                                                else
                                                        detect_menpai(me, strName, strId, strFName, intExp);
                                                break;
                                        }
                                        
                default:
                                        {
                                                detect_menpai(me, strName, strId, strFName, intExp);
                                                break;
                                        }
                                }
                        }
                //}
        }
    final_count();
    return;
}

