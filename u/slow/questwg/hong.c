// Code of ShenZhou
// Modified by xbc; add quests 06/21/97
// Modified by xuy; fixed crashing bugs in quests 08/11/97
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
int do_cry();
void create()
{
        set_name("洪七公", ({"hong qigong", "hong", "qigong"}));
        set("nickname", "九指神丐");
        set("gender", "男性");
        set("age", 75);
        set("long", 
"他一张长方脸，颌下微须，粗手大脚，身上衣服东一块西一块的打满了补丁，
却洗得干干净净，背上负着个朱红漆的大葫芦。\n");
        set("attitude", "peaceful");
        
        set("str", 35);
        set("int", 24);
        set("con", 30);
        set("dex", 30);

        set("rank", 10);
/*
        set("chat_chance", 1);
        set("chat_msg", ({
                "洪七公摸着肚皮叹道：“唉，好久没吃到蓉儿烧的小菜了……”\n",
        }));
        set("inquiry", ([
                "青竹令" : "老叫花可没功夫管这么多闲事，你去扬州找小左吧！\n",
        ]));

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
*/
        set("max_qi", 4000);
        set("max_jing", 3000);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 300);
        
        set("combat_exp", 3600000);
        set("score", 200000);
        set("death_times",180);

        set_skill("force", 400);             // 基本内功
        set_skill("huntian-qigong", 400);    // 混天气功
        set_skill("strike", 400);            // 基本掌法
        set_skill("xianglong-zhang", 400);   // 降龙十八掌
        set_skill("hand", 360);              // 基本手法
        set_skill("shexing-diaoshou", 400);  // 蛇形刁手 
        set_skill("dodge", 400);             // 基本躲闪
        set_skill("xiaoyaoyou", 400);        // 逍遥游
        set_skill("parry", 400);             // 基本招架
        set_skill("stick", 400);             // 基本棍杖
        set_skill("dagou-bang", 400);        // 打狗棒法
        set_skill("begging", 200);           // 叫化绝活
        set_skill("checking", 200);          // 道听途说
        set_skill("training", 240);          // 驭兽术
        set_skill("digging", 200);  
        
        map_skill("force", "huntian-qigong");
        map_skill("strike","xianglong-zhang");
        map_skill("hand",  "shexing-diaoshou");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("stick", "dagou-bang");
        
        prepare_skill("strike", "xianglong-zhang");

        create_family("丐帮", 17, "帮主");
        setup();
        
        carry_object("/d/gaibang/obj/budai")->set_amount(9);
        carry_object("/d/gaibang/obj/budai")->wear();
        if (clonep()) carry_object("/d/gaibang/obj/dahulu"); 
}

void init(){
        set_heart_beat(1);
        add_action("do_cry","cry");
}

void dest_ob(object ob,object me)
{
        
        me->move("/u/slow/questwg/jueding5");
        destruct(ob);

}

int do_cry()
{
        object me=this_player();
        object ob = this_object();
        object room,*inv;
        int i,j;

        j =0 ;
        room = environment(me);

        inv = all_inventory(room);
        for(i = 0,j=0; i < sizeof(inv); i++) {
                if( inv[i]->query("id")=="hong qigong" ) continue;
                j++;
       }
        if (j>1)
        command("say 你们这么人上华山干什么来了！\n");
        else if (!me->query("questwg"))
        {       
        
                command("haha");
                command("say 小娃儿，有什么伤心事快说给你公公听听！\n");
                tell_object(me,HIM"你觉得身体一轻，洪七公已拉着你跃上了华山绝顶！\n"NOR);

                call_out("dest_ob", 1, ob,me);
                
        }
        
}
