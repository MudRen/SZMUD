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
                                cname = "方";
                                ename = "fang";
                                break;
                        }
                case 1:
                        {
                                cname = "方";
                                ename = "fang";
                                break;
                        }
                case 2:
                        {
                                cname = "陈";
                                ename = "chen";
                                break;
                        }
                case 3:
                        {
                                cname = "张";
                                ename = "zhang";
                                break;
                        }
                case 4:
                        {
                                cname = "姬";
                                ename = "ji";
                                break;
                        }
                case 5:
                        {
                                cname = "林";
                                ename = "lin";
                                break;
                        }
                case 6:
                        {
                                cname = "段";
                                ename = "duan";
                                break;
                        }
                case 7:
                        {
                                cname = "阳";
                                ename = "yang";
                                break;
                        }
                case 8:
                        {
                                cname = "强";
                                ename = "chang";
                                break;
                        }
                case 9:
                        {
                                cname = "嘉";
                                ename = "jia";
                                break;
                        }
                case 10:
                        {
                                cname = "嘉";
                                ename = "jia";
                                break;
                        }
                }



                //MIDDLE LETTER
                switch(num2)
                {
                case 0:
                        {
                                cname = cname + "子";
                                ename = ename + "zi";
                                break;
                        }
                case 1:
                        {
                                cname = cname + "子";
                                ename = ename + "zi";
                                break;
                        }
                case 2:
                        {
                                cname = cname + "绍";
                                ename = ename + "shao";
                                break;
                        }
                case 3:
                        {
                                cname = cname + "中";
                                ename = ename + "zhong";
                                break;
                        }
                case 4:
                        {
                                cname = cname + "彦";
                                ename = ename + "yan";
                                break;
                        }
                case 5:
                        {
                                cname = cname + "政";
                                ename = ename + "zhen";
                                break;
                        }
                case 6:
                        {
                                cname = cname + "无";
                                ename = ename + "wu";
                                break;
                        }
                case 7:
                        {
                                cname = cname + "超";
                                ename = ename + "chao";
                                break;
                        }
                case 8:
                        {
                                cname = cname + "自";
                                ename = ename + "zi";
                                break;
                        }
                case 9:
                        {
                                cname = cname + "应";
                                ename = ename + "yin";
                                break;
                        }
                case 10:
                        {
                                cname = cname + "应";
                                ename = ename + "yin";
                                break;
                        }
                }



                //LAST LETTER
                switch(num3)
                {
                case 0:
                        {
                                cname = cname + "瑜";
                                ename = ename + "yu";
                                break;
                        }
                case 1:
                        {
                                cname = cname + "瑜";
                                ename = ename + "yu";
                                break;
                        }
                case 2:
                        {
                                cname = cname + "萱";
                                ename = ename + "shuan";
                                break;
                        }
                case 3:
                        {
                                cname = cname + "谋";
                                ename = ename + "mo";
                                break;
                        }
                case 4:
                        {
                                cname = cname + "真";
                                ename = ename + "zhen";
                                break;
                        }
                case 5:
                        {
                                cname = cname + "佑";
                                ename = ename + "yo";
                                break;
                        }
                case 6:
                        {
                                cname = cname + "鹤";
                                ename = ename + "he";
                                break;
                        }
                case 7:
                        {
                                cname = cname + "友";
                                ename = ename + "yao";
                                break;
                        }
                case 8:
                        {
                                cname = cname + "白";
                                ename = ename + "bai";
                                break;
                        }
                case 9:
                        {
                                cname = cname + "分";
                                ename = ename + "fen";
                                break;
                        }
                case 10:
                        {
                                cname = cname + "分";
                                ename = ename + "fen";
                                break;
                        }
                }



        set_name(cname, ({ ename }));
        //set_name("黑衣人", ({ "heiyi ren", "heiyi", "ren" }));
        set("gender", "男性");
        set("age", 30);
        set("long", "看上去像是一位高手。\n");

        set("combat_exp", 1000);
        set("shen_type", -1);
                set("inquiry", ([
                        "移动" : (: ask_move :),
                        "move" : (: ask_move :),
						"leave" : (: ask_move :),
						"出去" : (: ask_move :),
						"闪开" : (: ask_move :),
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
                        case "武当派":
                                {
                                        strMenpaiP = "wd";
                                        break;
                                }
                        case "少林派":
                                {
                                        strMenpaiP = "sl";
                                        break;
                                }
                        case "丐帮":
                                {
                                        strMenpaiP = "gb";
                                        break;
                                }
                        case "星宿派":
                                {
                                        strMenpaiP = "xx";
                                        break;
                                }
                        case "峨嵋派":
                                {
                                        strMenpaiP = "em";
                                        break;
                                }
                        case "大理段家":
                                {
                                        strMenpaiP = "dl";
                                        break;
                                }
                        case "古墓派":
                                {
                                        strMenpaiP = "gm";
                                        break;
                                }
                        case "白驼山":
                                {
                                        strMenpaiP = "bt";
                                        break;
                                }
                        case "华山派":
                                {
                                        strMenpaiP = "hs";
                                        break;
                                }
                        case "雪山派":
                                {
                                        strMenpaiP = "xs";
                                        break;
                                }
                        case "桃花岛":
                                {
                                        strMenpaiP = "th";
                                        break;
                                }
                        case "全真教":
                                {
                                        strMenpaiP = "qz";
                                        break;
                                }
                        case "昆仑派":
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
                                log_file("/job/new_family_job_neili", ob->query("name") + "(" + ob->query("id") + ") 60 秒内完成了工作   "+ctime(time())+"\n");
                        }

                        log_file("/job/new_family_job", ob->query("name") + "(" + ob->query("id") + ") 成功做了一次新版门派工作  "+ctime(time())+"\n");

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
                return "老子刚好今天气不顺。";
        }
        else 
        { 
                return 0; 
        } 
}