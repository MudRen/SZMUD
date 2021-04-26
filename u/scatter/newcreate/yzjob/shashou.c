// Code of ShenZhou
// zhang.c ������

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
        set("nickname", "��������");


        set("gender", "����");
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
        
        create_family("�䵱��", 1, "��ɽ��ʦ");
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
