// Code of ShenZhou
// zhang.c 张三丰

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "/kungfu/class/wudang/auto_perform.h"

int reset();
int auto_perform();
int ask_zwz();
string ask_tjsg();
string ask_zhenwu();
#define CANPIAN "/kungfu/class/wudang/obj/canpian"

void create()
{
        object zhenwu;
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
        set("nickname", "挡我者死");


        set("gender", "男性");
        set("age", 30);
        set("shen_type", -1);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        
        set("max_qi", 10000);
        set("max_jing", 10000);
        set("eff_jingli", 10000);
        set("max_jingli", 10000);
        set("neili", 20000);
        set("max_neili", 20000);
        set("jiali", 100);
        set("combat_exp", 0);
        set("score", 0);

        set_skill("force", 400);
        set_skill("taiji-shengong", 400);
        set_skill("dodge", 400);
        set_skill("tiyunzong", 400);
        set_skill("cuff", 400);
        set_skill("taiji-quan", 400);
        set_skill("parry", 400);
        set_skill("sword", 400);
        set_skill("strike", 400);
        set_skill("mian-zhang", 400);
        set_skill("taiji-jian", 400);
        set_skill("taoism", 400);
        set_skill("literate", 400);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        map_skill("strike", "mian-zhang");
        prepare_skill("cuff", "taiji-quan");
        prepare_skill("strike", "mian-zhang");
        
        create_family("武当派", 1, "开山祖师");
        set("class", "taoist");
        set("chat_chance", 80);
        set("chat_msg", ({
                (: reset :),
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        setup();
        if( clonep() )
        {
                zhenwu=carry_object("/clone/unique/zhenwu");
                if( objectp(zhenwu) ) zhenwu->wield();
                else carry_object("/clone/weapon/zhujian")->wield();
                carry_object("/d/wudang/obj/greyrobe")->wear();
        }
}
