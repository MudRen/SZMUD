//heiyiren.c
//Code by Scatter

#include <ansi.h>
#define SAVE_NPC "/family_job/savenpc"

inherit NPC;
string ask_move();

void create()
{
        int num1, num2, num3;
        string cname1, cname2, cname3, ename1, ename2, ename3;
                
        num1 = (int)random(11);
        num2 = (int)random(11);
        num3 = (int)random(11);

        //FIRST NAME
        switch(num1)
        {
        case 0:
                {
                        cname1 = "方";
                        ename1 = "fang";
                        break;
                }
        case 1:
                {
                        cname1 = "王";
                        ename1 = "wang";
                        break;
                }
        case 2:
                {
                        cname1 = "陈";
                        ename1 = "chen";
                        break;
                }
        case 3:
                {
                        cname1 = "张";
                        ename1 = "zhang";
                        break;
                }
        case 4:
                {
                        cname1 = "姬";
                        ename1 = "ji";
                        break;
                }
        case 5:
                {
                        cname1 = "林";
                        ename1 = "lin";
                        break;
                }
        case 6:
                {
                        cname1 = "段";
                        ename1 = "duan";
                        break;
                }
        case 7:
                {
                        cname1 = "杨";
                        ename1 = "yang";
                        break;
                }
        case 8:
                {
                        cname1 = "周";
                        ename1 = "zhou";
                        break;
                }
        case 9:
                {
                        cname1 = "田";
                        ename1 = "tian";
                        break;
                }
        case 10:
                {
                        cname1 = "朱";
                        ename1 = "zhu";
                        break;
                }
    }//switch(num1)

        //MIDDLE LETTER
        switch(num2)
        {
        case 0:
                {
                        cname2 = "子";
                        ename2 = "zi";
                        break;
                }
        case 1:
                {
                        cname2 = "武";
                        ename2 = "wu";
                        break;
                }
        case 2:
                {
                        cname2 = "绍";
                        ename2 = "shao";
                        break;
                }
        case 3:
                {
                        cname2 = "中";
                        ename2 = "zhong";
                        break;
                }
        case 4:
                {
                        cname2 = "彦";
                        ename2 = "yan";
                }
        case 5:
                {
                        cname2 = "政";
                        ename2 = "zhen";
                        break;
                }
        case 6:
                {
                        cname2 = "云";
                        ename2 = "yun";
                        break;
                }
        case 7:
                {
                        cname2 = "超";
                        ename2 = "chao";
                        break;
                }
        case 8:
                {
                        cname2 = "志";
                        ename2 = "zhi";
                        break;
                }
        case 9:
                {
                        cname2 = "少";
                        ename2 = "shao";
                        break;
                }
        case 10:
                {
                        cname2 = "应";
                        ename2 = "yin";
                        break;
                }
        }//end switch(num2)

        //LAST LETTER
        switch(num3)
        {
        case 0:
                {
                        cname3 = "峰";
                        ename3 = "feng";
                        break;
                }
        case 1:
                { 
                        cname3 = "瑜";
                        ename3 = "yu";
                        break;
                }
        case 2:
                {
                        cname3 = "萱";
                        ename3 = "xuan";
                        break;
                }
        case 3:
                {
                        cname3 = "谋";
                        ename3 = "mou";
                        break;
                }
        case 4:
                {
                        cname3 = "真";
                        ename3 = "zhen";
                        break;
                }
        case 5:
                {
                        cname3 = "佑";
                        ename3 = "you";
                        break;
                }
        case 6:
                {
                        cname3 = "鹤";
                        ename3 = "he";
                        break;
                }
        case 7:
                {
                        cname3 = "友";
                        ename3 = "you";
                        break;
                }
        case 8:
                {
                        cname3 = "白";
                        ename3 = "bai";
                        break;
                }
        case 9:
                {
                        cname3 = "玄";
                        ename3 = "xuan";
                        break;
                }
        case 10:
                {
                        cname3 = "分";
                        ename3 = "fen";
                        break;
                }
        }//end switch(num3)


        set_name(cname1+cname2+cname3, ({ ename1+" "+ename2+ename3, ename1 }));
        set("gender", "男性");
        set("age", 30);
    set("long", "他看上去像是一位武林高手。\n");

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
}//end create()


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
			intExp = random(200) + 600;
			ob->add("potential", ob->query("max_potential"));
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
			}//switch
		}//endif
                

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
				ob->delete("menpai/gxd");
			ob->set("family_job/password", ropen);
		}//if

        ob->add("menpai/gxd", 10);
		if(random(100) > 92)
		{
			ob->add("shenzhou/pts", 1);
			tell_object(ob,HIC"恭喜你获得神州贡献度\n");
			log_file("/job/fj_gxd", ob->query("name") + "(" + ob->query("id") + ") 获得了一点神州贡献度  "+ctime(time())+"\n");
		}

        //END OF SETTING UP CONNECTION STRING

        if(query("c_time"))
        {
                ob->add("max_neili", 1);
                ob->add("combat_exp", 100);
                log_file("/job/new_family_job_neili", ob->query("name") + "(" + ob->query("id") + ") 60 秒内完成了工作   "+ctime(time())+"\n");
        }//if

        log_file("/job/new_family_job", ob->query("name") + "(" + ob->query("id") + ") 成功做了一次新版门派工作  "+ctime(time())+"\n");
        
        ::die();
}
}//end die()

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