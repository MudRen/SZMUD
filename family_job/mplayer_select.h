int do_mp_check_user(object ob, string strMenpai) 
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



    if(!ob->query("env/beta_family_job"))
    {
        return 0;
    
    }


    if(environment(ob)->query("no_fight"))
    {
        return 0;
    }
    return 1;
}

void mplayer_get_user()
{
        object me, *players;
    string strName, strId, strFName, strMenpai, *MenpaiList;
        string strJobMsg;
    int i, j, total, intExp, count;


        plist = allocate(13);
        k = 0;
    MenpaiList = ({"�䵱��","������","ؤ��","������","������","����μ�","��Ĺ��","����ɽ","��ɽ��","ѩɽ��","�һ���","ȫ���","������"});

    for(i=0;i<sizeof(MenpaiList);i++)
    {
        write("���ڷ���"+MenpaiList[i]+"�Ĺ���\n");
        players = filter_array(users(), "do_mp_check_user", this_object(), MenpaiList[i]);
        /*
                if(!query("job_enable"))
        {
                        write("���ɹ�����ֹ\n");
            return;
        }
                */
        if(!sizeof(players))
        {
            write("����"+MenpaiList[i]+"�Ĺ���û����������\n");
            continue;
        }
        else
        {
            total = sizeof(players);
            j = random(total);
                        plist[k] = players[j];
                        k = k + 1;
                }
        }
        do_mp_setup();
}
