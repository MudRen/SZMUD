//tracy & lnere
// gift.c
#include <ansi.h>
#include <room.h>
inherit ITEM;
void create()
{
          switch( random(10) ){
                case 0:
                set_name(HIW"玉兔"NOR, ({ "yu tu","tu"}) );
                set("long", "这是一只可爱的小白兔，通体洁白如玉。红红的眼睛一眨不眨的盯着你。\n");
                set("unit","只");
                break;
                case 1:
                set_name(MAG"紫云马"NOR, ({ "ziyun ma", "ma" }) );
                set("long", "此马四蹄如鬓,身上染有点点的紫色斑点,犹如一朵朵紫色的火云飞奔翻腾。\n这定是一匹一日千里的良驹。\n");
                set("unit","匹");
                break;
                case 2:
                set_name(HIR"诸葛遗书"NOR, ({ "zhuge book", "book" }) );
                set("long", "这是一本三国时期诸葛亮留下的凝聚他全部智慧的古书,早已失传以久。\n据说得到它的人会成为再世诸葛。\n");
                set("unit","本");
                break;
                case 3:
                set_name(HIC"无字天书"NOR, ({ "wuzi shu", "shu"}) );
                set("long", "这是一本厚厚的由竹简制成的书,深褐色的斑点提示你这本书年代久远,\n奇怪的是这本书既无书名又无作者。\n");
                set("unit","本");
                break;
                case 4:
                set_name(HIR"冰晶酒杯"NOR, ({ "jiu bei","bei" }) );
                set("long", "这是一杯晶莹剔透的酒杯,里面装满了酒。\n");
                set("unit","个");
                break;
                case 5:
                set_name(HIR"麒麟樽"NOR, ({ "qilin zun","zun" }) );
                set("long", "这是个周边都镶着无数金色麒麟方樽,通体金光闪闪,樽中所盛的酒散发出阵阵的沉厚的韵香。\n一看既知是个难得的宝物。\n");
                set("unit","个");
                break;
                case 6:
                set_name(HIR"霸王鼎"NOR, ({ "bawang ding","ding" }) );
                   set("long", "这是一个色彩斑斓由纯铜制成的四角方鼎,鼎中盛着千百年来人们上香所燃尽的香灰。\n这鼎少说也有千斤的重量。\n");
                set("unit","个");
                break;
                case 7:
                set_name(HIR"火云兽"NOR, ({ "huoyun shou","shou" }) );
                set("long", "这是一头似马似驼的四蹄动物,通体白色,只是一缕火红的棕毛沿背部直延下去,\n四肢从上到下,逐渐由白变红,四蹄殷红如血,看上如犹如踏在一团火云之上。\n");
                set("unit","头");
                break;
                default:
                set_name(HIR"火云兽"NOR, ({ "huoyun shou", "shou" }) );
                set("long","这是一头似马似驼的四蹄动物,通体白色,只是一缕火红的棕毛沿背部直延下去,\n四肢从上到下,逐渐由白变红,四蹄殷红如血,看上如犹如踏在一团火云之上。\n");
                set("unit","头");    
                break;  
      }
                set("no_get","不防试试拿(na)");
                setup();
}
void init()
{
        add_action("do_get", "na");
        add_action("do_ride", "shang");
}
int do_get(string arg)
{ 
        object  ob=this_object();
        object  me=this_player(),gold;
              string id=me->query("id");
         if (!arg) return 0;
                if (ob->query("giftp")!=id) return 0;
          if (arg == "tu" && ob->query("id")=="yu tu" && ob->query("giftp")==id) {
               me->add_temp("apply/dexerity",1);
               message_vision("$N慢慢靠近玉兔，突然伸手将"+ob->query("name")+"紧紧的抓住，你成功了！\n",me);
               tell_object(me,"恭喜你，你的临时身法增加了1点！\n");
         }  
         else if (arg == "shu" && ob->query("id")=="wuzi shu" &&  ob->query("giftp")==id) {
               me->add_temp("apply/intelligence",1);
               message_vision("$N将此书拿起,翻了几页,居然都是空空白白的无一字,突然中缝处有一行小字吸引了$N的注意:得此书者,得天道！\n",me);
               tell_object(me,"恭喜你，你的临时身法增加了1点！\n");
         }
         else if (arg == "book" && ob->query("id")=="zhuge book" &&  ob->query("giftp")==id) {
               me->add_temp("apply/intelligence",1);
               message_vision("$N掸去书上的浮尘,小心翼翼的捡起来翻看,书中的治国滔畴,兵家神计如当世再现般映现在$N眼前。\n",me);
               tell_object(me,"恭喜你，你的临时悟性增加了1点！\n");
         }
         else if (arg == "bei" && ob->query("id")=="jiu bei" &&  ob->query("giftp")==id) {
               me->add_temp("apply/constitution", 1);     
               message_vision("$N将此杯拿起,一股浓浓的酒香扑鼻而来。$N来不及细想,一仰头喝把酒杯里的酒喝个干净。\n突然$N觉得一股暖流自丹田急速流向全身,整个身体通泰暖和,筋骨舒畅。\n原来这是由天山千山冰川酿制而成的冰晶酒,久服可延年益寿。\n",me);
               tell_object(me,"恭喜你，你的临时根骨增加了1点！\n");
          }
         else if (arg == "zun" && ob->query("id")=="qilin zun" &&  ob->query("giftp")==id) {
               me->add_temp("apply/constitution", 1);     
               message_vision("$N捧起"+ob->query("name")+"，慢慢的喝下樽中美酒，$N只觉一条细细的热线从喉直入小腹，由小腹扩散至四肢百骇，使$N功力大增。\n",me);
               tell_object(me,"恭喜你，你的临时根骨增加了1点！\n");
          }                 
         else if (arg == "ding" && ob->query("id")=="bawang ding" &&  ob->query("giftp")==id) {
               me->add_temp("apply/strength", 1);     
               message_vision("$N扎了一个马步,两手紧紧抓住两侧的鼎缘,气运丹田，突然发力，这定在这此地的"+ob->query("name")+"已经被$N高高的举起。\n",me);
               tell_object(me,"恭喜你，你的临时臂力增加了1点！\n");
          }
         else if (arg == "shou" && ob->query("id")=="huoyun shou" &&  ob->query("giftp")==id) {
               me->add_temp("apply/strength", 1);     
               message_vision("$N从后面慢慢靠近"+ob->query("name")+",却没料到它突然转身,一声嘶鸣,前蹄高高抬起,向$N扑了过来。\n$N心中暗想：糟糕！,还未来及得反应,只见"+ob->query("name")+"化作一道金光钻入$N的体内,\n$N只觉如烈火焚身,良久,这烈焰逐渐在丹田凝聚成为一点而后就消失无踪了。\n",me);
               tell_object(me,"恭喜你，你的临时臂力增加了1点！\n");
                }
            else if (arg == "ma" && ob->query("id")=="ziyun ma" &&  ob->query("giftp")==id) {
               tell_object(me,"你不可以将马拿起来！不防试试上(shang)马。\n");
               return 1;
                }
                 else return 0;
              if (random(40)==1){
                gold = new("/clone/money/gold");
                gold->set_amount(100);
                gold->move(me);
                 }
                        else if (random(10)==1){
                gold = new("/clone/money/gold");
                gold->set_amount(10);
                gold->move(me);
                 }
                        else if (random(1000)==1) {          
                            new("/clone/drug/pldan")->move(me);
                        }  
                        else if (random(100)==1) {
                            new("/clone/drug/jiuzhuan")->move(me);
                        }
                        else if (random(40)==1) {
                            new("/clone/drug/puti-zi")->move(me);
                        }
                        else if (random(40)==1) {
                            new("/clone/drug/sheli-zi")->move(me);
                        }
               destruct(ob);
               return 1;
  }
int do_ride(string arg)
{ 
               object  ob=this_object(),me=this_player(),gold;
            string id=me->query("id");
         if  (!arg) return 0;
                if (ob->query("giftp")!=id) return 0;
          if (arg == "ma" && ob->query("id")=="ziyun ma" && ob->query("giftp")==id) {
               me->add_temp("apply/dexerity",1);
               message_vision("$N悄悄地绕到马的侧面,提气运功一纵身骑上了"+ob->query("name")+"。 \n那马纵蹄飞奔,$N听得耳边呼呼的风声,如乘风御电一般全身飞腾起来。$N从这神驹的奔腾中对轻功似有领悟...\n",me);
               tell_object(me,"恭喜你，你的临时身法增加了1点！\n");
                       }
                   else return 0;
              if (random(40)==1){
                gold = new("/clone/money/gold");
                gold->set_amount(100);
                gold->move(me);
                 }
                        else if (random(10)==1){
                gold = new("/clone/money/gold");
                gold->set_amount(10);
                gold->move(me);
                 }
                        else if (random(1000)==1){          
                            new("/clone/drug/pldan")->move(me);
                        }  
                        else if (random(100)==1){
                            new("/clone/drug/jiuzhuan")->move(me);
                        }
                        else if (random(40)==1){
                            new("/clone/drug/puti-zi")->move(me);
                        }
                        else if (random(40)==1){
                            new("/clone/drug/sheli-zi")->move(me);
                        }
               destruct(ob);
               return 1;
        
}
