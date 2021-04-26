// gxd_request.h
// Code by Scatter
#define SAVE_NPC "/family_job/savenpc"

void tell_player_menpai_gxd(object me, object master)
{
        string strFNameP, strFNameM;
        string strMenpaiP, strMenpaiM;
        string ropen, fname, fnamepk, ropenk;
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

		//RESET CODE
		fnamepk = "family_job/password/"+strMenpaiP;
		ropenk = SAVE_NPC->do_load(fnamepk);
		if(ropenk != "NA")
		{
			if(me->query("family_job/password") != ropenk)
			{
                me->delete("menpai/gxd");
				me->set("menpai/gxd", 0);
				me->set("family_job/password", ropenk);
			}
		}
        
		
		fname = "family_job/"+strMenpaiP;
        ropen = SAVE_NPC->do_load(fname);
        mygxd = me->query("menpai/gxd");
        fropen = atoi(ropen);
        
        message_vision(CYN"$n��$N˵����Ŀǰ�����ɵ��ҳ϶�Ϊ"+ chinese_number(fropen) + "�㡣\n", me, master);
        message_vision(CYN"$n��$N˵������Ա����ɵ��ҳ϶�Ϊ"+ chinese_number(mygxd) + "�㡣��Ҫ����Ŭ������ȡ���´����ɴ���ϵõ����������\n", me, master);
        message_vision(CYN"$n˵�����������ҳ϶ȴﵽ��ǧ���ʱ�����ٿ��´ε����ɴ�ᡣ\n", me, master);

                if(!master->query_temp("meeting"))
                {
                        if(fropen > 3499)
                        {
                                CHANNEL_D->do_channel(master, "chat", sprintf("ȫ��%s���������ˣ�%s���ɴ�Ὣ������Ӻ�ʼ���������ϯ���Զ���Ȩ��", master->query("family/family_name"), master->query("family/family_name")));
                                master->set_temp("meeting", 1);
                                call_out("do_meeting", 300, master, fropen);
                        }
                }

        return;

}

int do_meeting(object master, int fropen)
{

	// DEFINE VARIBLES
        object obj, *inv, pid1, pid2, pid3;
        mapping skill_status;
        int i, j, z, gxd1=0, gxd2=0, gxd3=0, gxd;
        string *id, straward;
        string *sname;
        string fname, ropen, strFNameP, strMenpaiP, rndnums;
        int k, point, count, new_shen, new_exp, new_pot, rndnum;

        inv = all_inventory(environment(master));
        if( !sizeof(inv) )
                return notify_fail("����û���κζ�����\n");
        

		if(fropen < 3499)
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("ȫ��%s���������ˣ�����%s���ɴ���Ѿ������ˣ�����ȡ���ظ����顣", master->query("family/family_name"), master->query("family/family_name")));
			return 1;
		}


		// Find the Rank
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

                if(gxd1==0)
                {
                        gxd1=inv[i]->query("menpai/gxd");
                        pid1 = inv[i];
                        continue;
                }


				gxd = inv[i]->query("menpai/gxd");


				if(gxd > gxd1)
				{
						gxd2=gxd1;
						gxd1=inv[i]->query("menpai/gxd");
						pid2=pid1;
						pid1 = inv[i];
						continue;
				}

				if(gxd2==0)
				{
						gxd2=inv[i]->query("menpai/gxd");
						pid2 = inv[i];
						continue;
				}

				if(gxd > gxd2)
				{
						gxd3=gxd2;
						gxd2=inv[i]->query("menpai/gxd");
						pid3=pid2;
						pid2 = inv[i];
						continue;
				}

				if(gxd3==0)
				{
						gxd3=inv[i]->query("menpai/gxd");
						pid3 = inv[i];
						continue;
				}
         
		}



		// RESET EVERYONE'S GXD on PRESENT
		for(z=0; z<sizeof(inv); z++) 
        {
			inv[z]->set("menpai/gxd", 0);
        }



		// ERROR CHECKING, IF NO SUCH ID
		if(gxd1!=0)
		{
			if(pid1->query("id") == master->query("id"))
			{
				gxd1=0;
			}
		}

        // ERROR CHECKING, IF NO SUCH ID
		if(gxd2!=0)
		{
			if(pid2->query("id") == master->query("id"))
			{
				gxd2=0;
			}
		}


		// ERROR CHECKING, IF NO SUCH ID
		if(gxd3!=0)
		{
			if(pid3->query("id") == master->query("id"))
			{
				gxd3=0;
			}
		}


		// DISPLAY MESSAGE
		if(gxd1==0)
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("��һ�����˻�á�"));
		}
		else
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("��ϲ%s����%s(%s)��õ�һ����", master->query("family/family_name"), pid1->query("name"), pid1->query("id")));
		}


		if(gxd2==0)
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("�ڶ������˻�á�"));
		}
		else
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("��ϲ%s����%s(%s)��õڶ�����", master->query("family/family_name"), pid2->query("name"), pid2->query("id")));
		}

		if(gxd3==0)
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("���������˻�á�"));
		}
		else
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("��ϲ%s����%s(%s)��õ�������", master->query("family/family_name"), pid3->query("name"), pid3->query("id")));
		}
		

		if(gxd1==0)
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("�ܿ�ϧ�����%sû���˳�ϯ���ɻ��顣", master->query("family/family_name")));
		}
		else
		{

			// START TO REWARD Player
        if(gxd1 > 2800)
        {
                straward="��һ������һ��㾭��ֱ����ǧ��Ǳ�ܣ���ʮ���������Լ��书�ȼ�ȫ����������\n";
                
                if ( mapp(skill_status = pid1->query_skills()) ) 
                {
                        skill_status = pid1->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid1->improve_skill(sname[k], point+1); 
                        }
						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid1->improve_skill(sname[k], point+1); 
                        }
						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid1->improve_skill(sname[k], point+1); 
                        }
                }

                pid1->add("max_neili", 20);
                pid1->add("combat_exp", 10000);
                pid1->add("potential", 3000);
                
        }


        else if(gxd1 > 2200)
        {
                straward="��һ��������ǧ�㾭��ֱ����ǧ��ٵ�Ǳ�ܣ�ʮ����������Լ��书�ȼ�ȫ����������\n";
                
                if ( mapp(skill_status = pid1->query_skills()) ) 
                {
                        skill_status = pid1->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid1->improve_skill(sname[k], point+2); 
                        }

						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid1->improve_skill(sname[k], point+1); 
                        }

                }

                pid1->add("max_neili", 15);
                pid1->add("combat_exp", 7000);
                pid1->add("potential", 2500);
                
        }

        else if(gxd1 > 1300)
        {
                straward="��һ��������ǧ�㾭��ֱ��һǧ��ٵ�Ǳ�ܣ�ʮ���������Լ��书�ȼ�ȫ������һ��\n";
                
                if ( mapp(skill_status = pid1->query_skills()) ) 
                {
                        skill_status = pid1->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid1->improve_skill(sname[k], point+1); 
                        }
                }

                pid1->add("max_neili", 10);
                pid1->add("combat_exp", 5000);
                pid1->add("potential", 1500);
                
        }


        else if(gxd1 > 670)
        {
                straward="��һ��������ǧ�㾭��ֱ����ٵ�Ǳ�ܣ��Լ��������\n";

                pid1->add("max_neili", 5);
                pid1->add("combat_exp", 3000);
                pid1->add("potential", 500);
        }


        else if(gxd1 > 150)
        {
                straward="��һ������һǧ�㾭��ֱ���Լ���ٵ�Ǳ��\n";

                pid1->add("combat_exp", 1000);
                pid1->add("potential", 500);
                
        }


        else
        {
                straward="��һ��������ٵ㾭��ֱ���Լ�������ʮ��Ǳ��\n";

                pid1->add("combat_exp", 500);
                pid1->add("potential", 250);
                
        }
		
}
		
		//�ڶ�����ʼ

		if(gxd2==0)
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("�ܿ�ϧ�����%sû���˳�ϯ���ɻ��顣", master->query("family/family_name")));
		}
		else
		{
		if(gxd2 > 2800)
        {
                straward = straward + "�ڶ�������һ��㾭��ֱ����ǧ��Ǳ�ܣ���ʮ���������Լ��书�ȼ�ȫ����������\n";
                
                if ( mapp(skill_status = pid2->query_skills()) ) 
                {
                        skill_status = pid2->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid2->improve_skill(sname[k], point+3); 
                        }

						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid2->improve_skill(sname[k], point+3); 
                        }

						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid2->improve_skill(sname[k], point+3); 
                        }
                }

                pid2->add("max_neili", 20);
                pid2->add("combat_exp", 10000);
                pid2->add("potential", 3000);
                
        }


        else if(gxd2 > 2200)
        {
                straward = straward + "�ڶ���������ǧ�㾭��ֱ����ǧ��ٵ�Ǳ�ܣ�ʮ����������Լ��书�ȼ�ȫ����������\n";
                
                if ( mapp(skill_status = pid2->query_skills()) ) 
                {
                        skill_status = pid2->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid2->improve_skill(sname[k], point+2); 
                        }

						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid2->improve_skill(sname[k], point+2); 
                        }
                }

                pid2->add("max_neili", 15);
                pid2->add("combat_exp", 7000);
                pid2->add("potential", 2500);
                
        }

        else if(gxd2 > 1300)
        {
                straward = straward + "�ڶ���������ǧ�㾭��ֱ��һǧ��ٵ�Ǳ�ܣ�ʮ���������Լ��书�ȼ�ȫ������һ��\n";
                
                if ( mapp(skill_status = pid2->query_skills()) ) 
                {
                        skill_status = pid2->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid2->improve_skill(sname[k], point+1); 
                        }
                }

                pid2->add("max_neili", 10);
                pid2->add("combat_exp", 5000);
                pid2->add("potential", 1500);
                
        }


        else if(gxd2 > 670)
        {
                straward = straward + "�ڶ���������ǧ�㾭��ֱ����ٵ�Ǳ�ܣ��Լ��������\n";

                pid2->add("max_neili", 5);
                pid2->add("combat_exp", 3000);
                pid2->add("potential", 500);
        }


        else if(gxd2 > 150)
        {
                straward = straward + "�ڶ�������һǧ�㾭��ֱ���Լ���ٵ�Ǳ��\n";

                pid2->add("combat_exp", 1000);
                pid2->add("potential", 500);
                
        }


        else
        {
                straward = straward + "�ڶ���������ٵ㾭��ֱ���Լ�������ʮ��Ǳ��\n";

                pid2->add("combat_exp", 500);
                pid2->add("potential", 250);
                
        }

		}




		//��������ʼ

		if(gxd3==0)
		{
			CHANNEL_D->do_channel(master, "chat", sprintf("�ܿ�ϧ�����%sû���˳�ϯ���ɻ��顣", master->query("family/family_name")));
		}
		else
		{

		if(gxd3 > 2800)
        {
                straward = straward + "����������һ��㾭��ֱ����ǧ��Ǳ�ܣ���ʮ���������Լ��书�ȼ�ȫ����������\n";
                
                if ( mapp(skill_status = pid3->query_skills()) ) 
                {
                        skill_status = pid3->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid3->improve_skill(sname[k], point+3); 
                        }

						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid3->improve_skill(sname[k], point+3); 
                        }

						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid3->improve_skill(sname[k], point+3); 
                        }
                }

                pid3->add("max_neili", 20);
                pid3->add("combat_exp", 10000);
                pid3->add("potential", 3000);
                
        }


        else if(gxd3 > 2200)
        {
                straward = straward + "������������ǧ�㾭��ֱ����ǧ��ٵ�Ǳ�ܣ�ʮ����������Լ��书�ȼ�ȫ����������\n";
                
                if ( mapp(skill_status = pid3->query_skills()) ) 
                {
                        skill_status = pid3->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid3->improve_skill(sname[k], point+2); 
                        }

						for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid3->improve_skill(sname[k], point+2); 
                        }
                }

                pid3->add("max_neili", 15);
                pid3->add("combat_exp", 7000);
                pid3->add("potential", 2500);
                
        }

        else if(gxd3 > 1300)
        {
                straward = straward + "������������ǧ�㾭��ֱ��һǧ��ٵ�Ǳ�ܣ�ʮ���������Լ��书�ȼ�ȫ������һ��\n";
                
                if ( mapp(skill_status = pid3->query_skills()) ) 
                {
                        skill_status = pid3->query_skills();
                        sname = keys(skill_status);
                        count = sizeof(skill_status);

                        for(k=0; k<sizeof(skill_status); k++)
                        {
                                point = (skill_status[sname[k]]+1)*(skill_status[sname[k]]+1)+1;
                                while ( (point /= 2) > 0 )
                                        pid3->improve_skill(sname[k], point+1); 
                        }
                }

                pid3->add("max_neili", 10);
                pid3->add("combat_exp", 5000);
                pid3->add("potential", 1500);
                
        }


        else if(gxd3 > 670)
        {
                straward = straward + "������������ǧ�㾭��ֱ����ٵ�Ǳ�ܣ��Լ��������\n";

                pid3->add("max_neili", 5);
                pid3->add("combat_exp", 3000);
                pid3->add("potential", 500);
        }


        else if(gxd3 > 150)
        {
                straward = straward + "����������һǧ�㾭��ֱ���Լ���ٵ�Ǳ��\n";

                pid3->add("combat_exp", 1000);
                pid3->add("potential", 500);
                
        }


        else
        {
                straward = straward + "������������ٵ㾭��ֱ���Լ�������ʮ��Ǳ��\n";

                pid3->add("combat_exp", 500);
                pid3->add("potential", 250);
                
        }
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

        fname = "family_job/password/"+strMenpaiP;
        rndnums = "" + rndnum;
		SAVE_NPC->do_save(fname, rndnum);
        
		fname = "family_job/"+strMenpaiP;
        rndnums = "0";

	    SAVE_NPC->do_save(fname, rndnum);
        return 1;
}