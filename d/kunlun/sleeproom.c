// sleeproom.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
set("short","卧室");
        set("long",@long
这里是何太冲最宠爱的第五小妾五姑的卧房。刚一进房，扑鼻便是一股药
气，里面还能闻到一股十分古怪的气息，过了片刻，更觉得这气息忽浓忽淡，
甚是奇特。床上躺着一个人，这人面向帐里，喘气甚急，象是扯着风箱。窗
子(window)都是紧紧关着。
long);

set("item_desc", ([
"window" : "房里很闷，你不禁想打开窗子透透气。\n",
"床" : "一张楠木绣榻，靠墙的床脚边有一小洞(hole)。\n",
    "hole" : "一个只有拇指般大的小洞，洞边非常光滑，似乎经常有东西出入。\n",
]));

set("objects",([
 "/kungfu/class/kunlun/zhanchun.c" :   1,
   "/d/kunlun/npc/wugu.c" : 1,
]));

set("exits", ([
"east" : __DIR__"tieqinju",
]));
          set("no_clean_up", 0);
create_door("east", "小门", "west", DOOR_CLOSED);
          setup();
}

int she_come(object me)
{
   object ob;
   if (!me || environment(me)!=this_object()) return 1;
   ob=new( "/d/kunlun/npc/jinguanshe");
   ob->move(this_object());
   ob=new( "/d/kunlun/npc/yinguanshe");
   ob->move(this_object());
   if (present("xionghuang", me) && objectp(present("wu gu",this_object()))){
        message("vision","两个黑影突然从小洞里钻了出来，窜上绣榻，一口咬住五姑的脚指。\n",this_object());
        call_out("wugu_bian",3,me); 
        }
   else 
   message("vision","两个黑影突然从小洞里钻了出来。\n",this_object());
}
void init()
{
    if (objectp(present("wu gu",this_object())))
        set("long", @LONG
一进门，扑鼻便是一股药气，一张绣榻放在墙角，垂着细纱。揭开帐子，只
见一个脸肿得象南瓜般的女人躺在床上。
LONG
        );
        else
        set("long", "一进门，扑鼻便是一股药气，一张绣榻放在墙角，垂着细纱。\n");
}
void wugu_bian(object me)
{
        object ob,masterhe,room;
        if (!me || environment(me)!=this_object() ) return;
        if (objectp(ob=present("wu gu",this_object()))){
                ob->set("per",35); 
                ob->set("long","她是何太冲的五姨太。\n");
                set("long", @LONG
一进门，扑鼻便是一股药气，一张绣榻放在墙角，垂着细纱。一位绝色佳丽手
拿梳子，正坐在床边梳头。
LONG
                );
                  masterhe=find_living("he taichong");
                if (masterhe && environment(masterhe)){
                        message("vision",masterhe->name()+"急急忙忙走开了。\n",environment(masterhe));
                        masterhe->move(this_object());
                        message("vision",masterhe->name()+"兴冲冲地跑了进来。\n",this_object());
                        message_vision(HIC "$N拉着$n"+HIC+"的手，温柔地默默对视。目光中孕含着千种柔情，万般蜜意。\n"+NOR,masterhe,ob);
                          if ((string)me->query("family/family_name")=="昆仑派"){
                                message_vision(CYN "$N对$n笑道：这位"+RANK_D->query_respect(me)+"治好了我爱妾的病，在下无以回报...\n" NOR,masterhe,me);
                                message_vision("$N从袖里拿出一本书，交给了$n。\n",masterhe,me);
                                ob=new("/d/kunlun/obj/lyj-book");
                CHANNEL_D->do_channel(me, "rumor", sprintf("%s弄到一本两仪剑谱。", me->query("name")));
                                ob->move(me);
                                message_vision(CYN "$N对$n说道：小小礼物，不成敬意。\n" NOR,masterhe,me);
                        }else{
                                if (!(room=find_object(__DIR__"mw")))
                                        room=load_object(__DIR__"mw");
                                message_vision(CYN "$N对$n说道：难得有你如此侠义的弟子。\n" NOR,masterhe,me);
                                message_vision("$N衣袖一挥，暗运内劲，将绣榻缓缓移开...\n露出一个洞口。\n",masterhe);
                                message_vision("突然从洞中生出一股吸力，$N暗叫不好，还是不由自主地掉进洞里...\n",me);
                                me->move(room);
                                message("vision",me->name()+"突然滚到你脚下。\n",room,({me}));
                                message_vision("$N微微一笑，依法将绣榻缓缓移回原处。\n",masterhe);
                        }
                }
        }
}
