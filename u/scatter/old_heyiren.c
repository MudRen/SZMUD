//heyiren.c
//Code by Scatter

#include <ansi.h>
#define SAVE_NPC "/family_job/savenpc"

inherit NPC;

string ask_move();

void create()
{
                int num1, num2, num3;
                string cname, ename;
                
                num1 = (int)random(10);
                num2 = (int)random(10);
                num3 = (int)random(10);


                //FIRST NAME
                switch(num1)
                {
                case 0:
                        {
                                cname = "��";
                                ename = "fang";
                                break;
                        }
                case 1:
                        {
                                cname = "��";
                                ename = "fang";
                                break;
                        }
                case 2:
                        {
                                cname = "��";
                                ename = "chen";
                                break;
                        }
                case 3:
                        {
                                cname = "��";
                                ename = "zhang";
                                break;
                        }
                case 4:
                        {
                                cname = "��";
                                ename = "ji";
                                break;
                        }
                case 5:
                        {
                                cname = "��";
                                ename = "lin";
                                break;
                        }
                case 6:
                        {
                                cname = "��";
                                ename = "duan";
                                break;
                        }
                case 7:
                        {
                                cname = "��";
                                ename = "yang";
                                break;
                        }
                case 8:
                        {
                                cname = "ǿ";
                                ename = "chang";
                                break;
                        }
                case 9:
                        {
                                cname = "��";
                                ename = "jia";
                                break;
                        }
                case 10:
                        {
                                cname = "��";
                                ename = "jia";
                                break;
                        }
                }



                //MIDDLE LETTER
                switch(num2)
                {
                case 0:
                        {
                                cname = cname + "��";
                                ename = ename + "zi";
                                break;
                        }
                case 1:
                        {
                                cname = cname + "��";
                                ename = ename + "zi";
                                break;
                        }
                case 2:
                        {
                                cname = cname + "��";
                                ename = ename + "shao";
                                break;
                        }
                case 3:
                        {
                                cname = cname + "��";
                                ename = ename + "zhong";
                                break;
                        }
                case 4:
                        {
                                cname = cname + "��";
                                ename = ename + "yan";
                                break;
                        }
                case 5:
                        {
                                cname = cname + "��";
                                ename = ename + "zhen";
                                break;
                        }
                case 6:
                        {
                                cname = cname + "��";
                                ename = ename + "wu";
                                break;
                        }
                case 7:
                        {
                                cname = cname + "��";
                                ename = ename + "chao";
                                break;
                        }
                case 8:
                        {
                                cname = cname + "��";
                                ename = ename + "zi";
                                break;
                        }
                case 9:
                        {
                                cname = cname + "Ӧ";
                                ename = ename + "yin";
                                break;
                        }
                case 10:
                        {
                                cname = cname + "Ӧ";
                                ename = ename + "yin";
                                break;
                        }
                }



                //LAST LETTER
                switch(num3)
                {
                case 0:
                        {
                                cname = cname + "�";
                                ename = ename + "yu";
                                break;
                        }
                case 1:
                        {
                                cname = cname + "�";
                                ename = ename + "yu";
                                break;
                        }
                case 2:
                        {
                                cname = cname + "��";
                                ename = ename + "shuan";
                                break;
                        }
                case 3:
                        {
                                cname = cname + "ı";
                                ename = ename + "mo";
                                break;
                        }
                case 4:
                        {
                                cname = cname + "��";
                                ename = ename + "zhen";
                                break;
                        }
                case 5:
                        {
                                cname = cname + "��";
                                ename = ename + "yo";
                                break;
                        }
                case 6:
                        {
                                cname = cname + "��";
                                ename = ename + "he";
                                break;
                        }
                case 7:
                        {
                                cname = cname + "��";
                                ename = ename + "yao";
                                break;
                        }
                case 8:
                        {
                                cname = cname + "��";
                                ename = ename + "bai";
                                break;
                        }
                case 9:
                        {
                                cname = cname + "��";
                                ename = ename + "fen";
                                break;
                        }
                case 10:
                        {
                                cname = cname + "��";
                                ename = ename + "fen";
                                break;
                        }
                }



        set_name(cname, ({ ename }));
        //set_name("������", ({ "heiyi ren", "heiyi", "ren" }));
        set("gender", "����");
        set("age", 30);
        set("long", "����ȥ����һλ���֡�\n");

        set("combat_exp", 1000);
        set("shen_type", -1);
                set("inquiry", ([
                        "�ƶ�" : (: ask_move :),
                        "move" : (: ask_move :),
						"leave" : (: ask_move :),
						"��ȥ" : (: ask_move :),
						"����" : (: ask_move :),
						"getout" : (: ask_move :),
						"go" : (: ask_move :),
        ])); 

        set("attitude", "heroism");
        set("c_time", 1);
        setup();
        //carry_object("/clone/misc/cloth")->wear();
		carry_object("/clone/armor/tiejia")->wear();
		call_out("do_time_up", 60);
}

void init()
{
        string pkid;
        pkid = query_temp("pkid");

        if(this_player()->query("id") == pkid)
        {
                command("kill "+pkid);
                this_object()->reincarnate();
        }
}


void do_time_up()
{
        delete("c_time");
        return;
}



void die()
{ 
        object ob, me;
        string strMenpaiP, strFNameP, fname, pdata, ropen;
        string fnamep, fdata;
        int cvalue, intExp;

        me = this_object();

        if( !living(this_object()) ) revive(1);

        if( objectp(ob = me->query_temp("last_damage_from")) ) 
        {
                if(ob->query("id") == query_temp("pkid"))
                {
						intExp = random(200) + 500;
                        ob->set("potential", ob->query("max_potential"));
                        ob->add("combat_exp", intExp);
                        
                        strFNameP = ob->query("family/family_name");
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


                        //SETTING UP CONNECTION STRING

                        fname = "family_job/"+strMenpaiP;
                        ropen = SAVE_NPC->do_load(fname);
                        cvalue = atoi(ropen);
                        cvalue = cvalue + 10;
                        
                                                
                                                pdata = "" + cvalue;
                                                fdata = "family_job/"+strMenpaiP;
                        SAVE_NPC->do_save(fdata, pdata);


                                                fnamep = "family_job/password/"+strMenpaiP;
                        ropen = SAVE_NPC->do_load(fnamep);
                        
                        if(ropen != "NA")
                        {
                                if(ob->query("family_job/password") != ropen)
                                {
                                        ob->delete("menpai/gxd");
                                        ob->set("family_job/password", ropen);
                                }
                        }

                        ob->add("menpai/gxd", 10);


                        //END OF SETTING UP CONNECTION STRING

                        if(query("c_time"))
                        {
                                ob->add("max_neili", 1);
								ob->add("combat_exp", 100);
                                log_file("/job/new_family_job_neili", ob->query("name") + "(" + ob->query("id") + ") 60 ��������˹���   "+ctime(time())+"\n");
                        }

                        log_file("/job/new_family_job", ob->query("name") + "(" + ob->query("id") + ") �ɹ�����һ���°����ɹ���  "+ctime(time())+"\n");

                }
        }
        ::die();
}


string ask_move()
{ 
        object player, room; 
        mapping exits; 
        string  *dirs; 
        
        player = this_player(); 
        if (this_player()->query("id") == query_temp("pkid")) 
        { 
                room = environment(this_object());
                exits = room->query("exits");
                dirs = keys(exits);
                command("go "+dirs[random(sizeof(dirs))]);
                return "���Ӹպý�������˳��";
        }
        else 
        { 
                return 0; 
        } 
}