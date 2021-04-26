// gxd_request.h
// Code by Scatter
#define SAVE_NPC "/family_job/savenpc"
inherit F_CLEAN_UP;

void tell_player_menpai_gxd(object me, object master)
{
        string strFNameP, strFNameM;
        string strMenpaiP, strMenpaiM;
        string ropen, fname;
        int mygxd;
        int fmygxd, fropen;

        strFNameP = me->query("family/family_name");
        strFNameM = master->query("family/family_name");

        switch(strFNameP)
        {
        case "�䵱��":
                {
                        strMenpaiP = "wd";
                        break;
                }
        case "������":
                {
                        strMenpaiP = "sl";
                        break;
                }
        case "ؤ��":
                {
                        strMenpaiP = "gb";
                        break;
                }
        case "������":
                {
                        strMenpaiP = "xx";
                        break;
                }
        case "������":
                {
                        strMenpaiP = "em";
                        break;
                }
        case "����μ�":
                {
                        strMenpaiP = "dl";
                        break;
                }
        case "��Ĺ��":
                {
                        strMenpaiP = "gm";
                        break;
                }
        case "����ɽ":
                {
                        strMenpaiP = "bt";
                        break;
                }
        case "��ɽ��":
                {
                        strMenpaiP = "hs";
                        break;
                }
        case "ѩɽ��":
                {
                        strMenpaiP = "xs";
                        break;
                }
        case "�һ���":
                {
                        strMenpaiP = "th";
                        break;
                }
        case "ȫ���":
                {
                        strMenpaiP = "qz";
                        break;
                }
        case "������":
                {
                        strMenpaiP = "kl";
                        break;
                }
        default:
                {
                        strMenpaiP = "error";
                }
        }



        switch(strFNameM)
        {
        case "�䵱��":
                {
                        strMenpaiM = "wd";
                        break;
                }
        case "������":
                {
                        strMenpaiM = "sl";
                        break;
                }
        case "ؤ��":
                {
                        strMenpaiM = "gb";
                        break;
                }
        case "������":
                {
                        strMenpaiM = "xx";
                        break;
                }
        case "������":
                {
                        strMenpaiM = "em";
                        break;
                }
        case "����μ�":
                {
                        strMenpaiM = "dl";
                        break;
                }
        case "��Ĺ��":
                {
                        strMenpaiM = "gm";
                        break;
                }
        case "����ɽ":
                {
                        strMenpaiM = "bt";
                        break;
                }
        case "��ɽ��":
                {
                        strMenpaiM = "hs";
                        break;
                }
        case "ѩɽ��":
                {
                        strMenpaiM = "xs";
                        break;
                }
        case "�һ���":
                {
                        strMenpaiM = "th";
                        break;
                }
        case "ȫ���":
                {
                        strMenpaiM = "qz";
                        break;
                }
        case "������":
                {
                        strMenpaiM = "kl";
                        break;
                }
        default:
                {
                        strMenpaiM = "error";
                }
        }


        if( strMenpaiM == "error" )
        {
                message_vision(CYN"$n��$N˵������λ׳ʿ�ʴ����˰ɣ�����ô֪�����������ء�\n", me, master);
                return;
        }

        if( strMenpaiP == "error" )
        {
                message_vision(CYN"$n��$N˵������λ׳ʿ�ʴ����˰ɣ�����ô֪�����������ء�\n", me, master);
                return;
        }

        if( strMenpaiM != strMenpaiP )
        {
                message_vision(CYN"$n��$N˵������λ׳ʿ�ʴ����˰ɣ�����ô֪�����������ء�\n", me, master);
                return;
        }

        fname = "family_job/"+strMenpaiP;
        ropen = SAVE_NPC->do_load(fname);
        mygxd = me->query("menpai/gxd");
        fropen = atoi(ropen);

        
        message_vision(CYN"$n��$N˵����Ŀǰ�����ɵĹ��׶�Ϊ"+ chinese_number(fropen) + "�㡣\n", me, master);
        message_vision(CYN"$n��$N˵������Ϊ�����������Ĺ���Ϊ"+ chinese_number(mygxd) + "�㡣��Ҫ����Ŭ������ȡ���´����ɴ���ϵõ����������\n", me, master);
        message_vision(CYN"$n˵���������ɹ��׶ȴﵽ��ǧ���ʱ�����ٿ��´ε����ɴ�ᡣ\n", me, master);

                if(!master->query_temp("meeting"))
                {
                        if(fropen > 3499)
                        {
                                CHANNEL_D->do_channel(master, "chat", sprintf("ȫ��%s���������ˣ�%s���ɴ�Ὣ������Ӻ�ʼ���������ϯ���Զ���Ȩ��", master->query("family/family_name"), master->query("family/family_name")));
                                master->set_temp("meeting", 1);
                                call_out("do_meeting", 300, master);
                        }
                }

        return;

}

int do_meeting(object master)
{
        object obj, *inv, pid;
        mapping skill_status;
        int i, j, gxd1, gxd2, gxd;
        string *id, straward;
        string *sname;
        string fname, ropen, strFNameP, strMenpaiP, rndnums;
        int k, point, count, new_shen, new_exp, new_pot, rndnum;

        inv = all_inventory(environment(master));
        if( !sizeof(inv) )
                return notify_fail("����û���κζ�����\n");
        
        for(i=0; i<sizeof(inv); i++) 
        {
                if( !master->visible(inv[i]) )
                {
                        continue;
                }

                if(inv[i]->query("family/family_name") != master->query("family/family_name"))
                {
                        continue;
                }

                if(!gxd1)
                {
                        gxd1=inv[i]->query("menpai/gxd");
                        pid = inv[i];
                        continue;
                }

                gxd2 = inv[i]->query("menpai/gxd");
                
                if(gxd2 > gxd1)
                {
                        pid = inv[i];
                        continue;
                }
                
        }

        CHANNEL_D->do_channel(master, "chat", sprintf("��ϲ%s����%s(%s)��ý�����", master->query("family/family_name"), pid->query("name"), pid->query("id")));

        gxd = pid->query("menpai/gxd");


        if(gxd > 3000)
        {
                straward="����һ��㾭��ֱ����ǧ��Ǳ�ܣ���ʮ���������Լ��书�ȼ�ȫ����������";
                
                if ( mapp(skill_status = pid->query_skills()) ) 
                {
                        skill_status = pid->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)/2+1;
                                while ( (point /= 2) > 0 )
                                        pid->improve_skill(sname[k], point+3); 
                        }
                }

                pid->add("max_neili", 20);
                pid->add("combat_exp", 10000);
                pid->add("potential", 3000);
                
        }


        else if(gxd > 2400)
        {
                straward="������ǧ�㾭��ֱ����ǧ��ٵ�Ǳ�ܣ�ʮ����������Լ��书�ȼ�ȫ����������";
                
                if ( mapp(skill_status = pid->query_skills()) ) 
                {
                        skill_status = pid->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)/2+1;
                                while ( (point /= 2) > 0 )
                                        pid->improve_skill(sname[k], point+2); 
                        }
                }

                pid->add("max_neili", 15);
                pid->add("combat_exp", 7000);
                pid->add("potential", 2500);
                
        }

        else if(gxd > 1500)
        {
                straward="������ǧ�㾭��ֱ��һǧ��ٵ�Ǳ�ܣ�ʮ���������Լ��书�ȼ�ȫ������һ��";
                
                if ( mapp(skill_status = pid->query_skills()) ) 
                {
                        skill_status = pid->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)/2+1;
                                while ( (point /= 2) > 0 )
                                        pid->improve_skill(sname[k], point+1); 
                        }
                }

                pid->add("max_neili", 10);
                pid->add("combat_exp", 5000);
                pid->add("potential", 1500);
                
        }


        else if(gxd > 870)
        {
                straward="������ǧ�㾭��ֱ����ٵ�Ǳ�ܣ��Լ��������";

                pid->add("max_neili", 5);
                pid->add("combat_exp", 3000);
                pid->add("potential", 500);
        }


        else if(gxd > 350)
        {
                straward="����һǧ�㾭��ֱ���Լ���ٵ�Ǳ��";

                pid->add("combat_exp", 1000);
                pid->add("potential", 500);
                
        }


        else
        {
                straward="������ٵ㾭��ֱ���Լ�������ʮ��Ǳ��";

                pid->add("combat_exp", 500);
                pid->add("potential", 250);
                
        }

        rndnum = random(5999);

        strFNameP = master->query("family/family_name");
                        switch(strFNameP)
                        {
                        case "�䵱��":
                                {
                                        strMenpaiP = "wd";
                                        break;
                                }
                        case "������":
                                {
                                        strMenpaiP = "sl";
                                        break;
                                }
                        case "ؤ��":
                                {
                                        strMenpaiP = "gb";
                                        break;
                                }
                        case "������":
                                {
                                        strMenpaiP = "xx";
                                        break;
                                }
                        case "������":
                                {
                                        strMenpaiP = "em";
                                        break;
                                }
                        case "����μ�":
                                {
                                        strMenpaiP = "dl";
                                        break;
                                }
                        case "��Ĺ��":
                                {
                                        strMenpaiP = "gm";
                                        break;
                                }
                        case "����ɽ":
                                {
                                strMenpaiP = "bt";
                                break;
                                }
                        case "��ɽ��":
                                {
                                        strMenpaiP = "hs";
                                        break;
                                }
                        case "ѩɽ��":
                                {
                                        strMenpaiP = "xs";
                                        break;
                                }
                        case "�һ���":
                                {
                                        strMenpaiP = "th";
                                        break;
                                }
                        case "ȫ���":
                                {
                                        strMenpaiP = "qz";
                                        break;
                                }
                        case "������":
                                {
                                        strMenpaiP = "kl";
                                        break;
                                }
                        default:
                                {
                                        strMenpaiP = "error";
                                }
                        }


        CHANNEL_D->do_channel(master, "chat", straward);
        master->delete_temp("meeting");

        write("mark1\n");
        fname = "family_job/password/"+strMenpaiP;
        rndnums = "" + rndnum;
    SAVE_NPC->do_save(fname, rndnum);
        
        
        write("mark2\n");
        fname = "family_job/"+strMenpaiP;
        rndnums = "0";
        
        write("mark3\n");
    SAVE_NPC->do_save(fname, rndnum);
        write("mark4\n");

        return 1;
}