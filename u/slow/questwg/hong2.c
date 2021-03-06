// Code of ShenZhou
// Modified by xbc; add quests 06/21/97
// Modified by xuy; fixed crashing bugs in quests 08/11/97
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
int do_chi(string arg);
int do_chaikai();

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
        set("jiali", 0);
        
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

void init()
{
        object ob, me;
        ::init();
        
        ob = this_player();
        if (interactive(ob) && !is_fighting() && !ob->query("questwg"))
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object me)
{
        object ob = this_object();
        command(HIW"say 伤心事暂且不提，先填饱肚子再说 。"NOR);
        message_vision(HIW"\n
$N支起铁锅烧了一锅雪水，又从一块大岩石边的泥土中挖出一只死公鸡来。
$n在雪光掩映下瞧得分明，只见鸡身上咬满了百来条七八寸长的大蜈蚣，红黑
相间，花纹斑斓，都在蠕蠕而动。$N拉住蜈蚣尾巴，一条条的抛在锅里。
那些蜈蚣挣扎一阵，便都给烫死了。\n
$N又起了油锅，将蜈蚣去壳炸至微黄之后加上作料拌匀，伸手往锅中提了
一条上来放入口中，轻轻嚼了几嚼，两眼微闭，叹了一口气，只觉天下之至乐，
无逾于此矣。\n
洪七公吃了十多条以后，向$n道：“我见过不少英雄好汉，杀头流血不皱半点眉
头，却没一个敢跟我老叫化吃一条蜈蚣。小娃娃，你敢不敢吃（chi）？”\n\n
"NOR,ob,me);
        
        add_action("do_chi","chi");
        
        return;
}
int do_chi(string arg)
{
        object me=this_player();
        object ob=this_object();
        if (!arg)
        return notify_fail(HIW"你要吃什么。\n"NOR);
        if (arg == "wugong")
        {
                remove_action("do_chi","chi");
                message_vision(HIW"
$N将一条蜈蚣放在口中一嚼。只一嚼将下去，但觉满嘴鲜美，又脆又香，清甜
甘浓，一生之中从未尝过如此异味，再嚼了几口，一骨碌吞了下去，又去挟第
二条来吃，连赞：“妙极，妙极。”\n"NOR,me);
                call_out("feng_out",5,ob,me);
        }
        else 
        return notify_fail(HIW"没有这样东西。\n"NOR);

        return 1;

}
void feng_out(object hong,object me)
{
        object feng;
        feng=new("/u/slow/questwg/feng");
        feng->move("/u/slow/questwg/jueding5");
        message_vision(CYN"
二人你抢我夺吃的甚是香甜，只听铎、铎、铎几声响，山角后转出来一人，身
子颠倒，双手各持石块，撑地而行，正是西毒欧阳锋。欧阳峰二话不说便向洪
七公发起攻击。\n\n"NOR,me);
        feng->kill_ob(hong);
          call_out("chai_out",10,hong,feng,me);

}

void chai_out(object hong,object feng,object me)
{
        
        feng->remove_all_killer();
        message_vision(HIW"
欧阳锋突然收起灵蛇杖，双腿一弯，蹲下身来，“阁”的一声大叫，运起蛤蟆
功劲力，双掌齐发，向前推出。这一推实乃他毕生功力之所聚。洪七公猛觉劲
风罩来，心知不妙，也是双掌向前平推。这一下是以硬接硬，刹那之间，两下
里竟然凝住不动。\n
二人僵持一会，欧阳锋头顶透出一缕缕的白气，渐渐越来越浓，就如蒸笼一般。
洪七公也是全力抵御。你眼见二人脸色大变，心想他二人再拚得一时三刻，非
同归于尽不可，若是上前拆开（chaikai），自己功力与他们相差太远 ，多半
分解不开，反而赔上自己一条性命。\n\n"NOR,feng,hong);
        add_action("do_chaikai","chaikai");
        call_out("chaikai_out",8,hong,feng,me);
}
int do_chaikai()
{
        object me=this_player();
        object hong =  this_object();
        object book;    
        object feng;

        feng = present("ouyang feng", environment(me));

        if (me->query("max_neili")<8000  || me->query("neili") <10000)
        {
                message_vision(HIC"
$N折了一根树干，走到二人之间盘膝坐下，运功护住全身，一咬牙，伸树干往
二人之间挑去，$N只觉一股大力从树干上传来，五脏六腑有如翻江倒海般，$N
象断了线的风筝般直坠入山下。\n"NOR,me);
                me->move("/d/huashan/sheshen");
                me->unconcious();
        }
        else 
        {
                message_vision(HIC"
$N折了一根树干，走到二人之间盘膝坐下，运功护住全身，一咬牙，伸树干往二
人之间挑去。这一挑居然毫不费力，二人的内力从树干上传来，被$N运内力一挡，
立即卸去。原来强弩之末不能穿鲁缟，北丐西毒虽然俱是当世之雄，但互耗多时，
均已精力无多。\n"NOR,me);
                hong->set("chaikai",1);
                tell_object(me,HIM"
你从洪七公和欧阳峰的战斗中获益菲浅。\n"NOR,me);
                  me->add("combat_exp",(30000+random(20000)));
                me->set("questwg",1);
                if (me->query("family/family_name") == "丐帮") 
                {
                          me->set("questwg",1);
                        tell_object(me,HIW"
欧阳锋哈哈大笑，叫道：“我与你斗了几十年，今日仍只是打成平手，老叫花当
真了得！”随即飘然下山。\n
洪七公向你道：“我有一套武功传给你。这武功向来只传本帮帮主，不传旁人，
今日你我有缘，我就把口诀传授给你。这本书记载着打狗棒法最后一招“天下无
狗”。若以后想要此书，就来丐帮总舵找我。”\n\n\n"NOR);
                        
                        book=new("/u/slow/questwg/dgb_book");
                        if (book)
                       {
                          book->move(me);
tell_object(me,HIY"你得到一本《打狗棒谱》。\n\n"NOR);
                        }

                }
                
                message_vision(HIW"
洪七公道：“此处天寒地冻，小娃娃不宜久留，不如随我一同下山。”洪七公携起
$n的手，几个起落，已跃下峰顶。\n\n "NOR,hong,me);
                me->move("/d/huashan/sheshen");
                tell_object(me,HIW"
洪七公拍了拍肚皮向你道：“老叫花要吃遍天下美食，不能与你同行了，你好自为
之吧！”只见人影晃动，霎时间就去的无影无踪。\n\n "NOR,hong,me);
                call_out("all_dest",1,feng,hong);
                
                

        
        }
        return 1;
}

void chaikai_out(object hong,object feng,object me)
{
        if (!hong->query("chaikai"))
        {
                message_vision(HIR"
$N和$n两人突然同时委顿在地，双目紧闭，面如死灰，一动也不动了，
原来二人已耗尽内力而死。北丐西毒数十年来反覆恶斗，互不相下，岂知竟同
时在华山绝顶归天,你只有黯然下山。\n"NOR,hong,feng);
           me->move("/d/huashan/sheshen");
        
                feng->die();
                hong->die();
        }
}
void all_dest(object feng,object hong)
{
        destruct(feng);
        destruct(hong);

}
