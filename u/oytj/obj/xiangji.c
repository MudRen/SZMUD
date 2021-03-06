// camera.c

#include <ansi.h>
#include <room.h>
#include <weapon.h>

inherit HAMMER;
              
string *msg_expression = ({
   "脸上露出愉快的微笑。",
   "躲在一边幸灾乐祸地笑。",
   "脸上露出狡诈的神情，大概又想到了什么坏主意了。",
   "绷着个脸扮酷。",
   "捧着肚子笑得前仰后合。",
   "眉头紧锁，不知在想什么心事。",
   "托着腮帮子故作深沉状。",
   "咬牙切齿，一副愤愤不平的样子。",
   "一脸的迷茫，不知道周围发生了什么事。",
   "咧着嘴傻乐。",
   "作天真状。",
   "闷闷不乐。",
   "骄傲地昂着头，满脸不屑的神情。",
   "痛苦得呲牙咧嘴，大概是牙痛得厉害。",
   "强颜欢笑，但掩饰不住心里的哀伤。",
   "眉飞色舞。",
   "一脸的尴尬相。",
   "脸上露出灿烂的笑容。",
   "笑得比哭还难看。",
   "强忍着不让自己哭出来。",
   "媚眼如丝。",
   "作小鸟依人状。",
   "开怀大笑，露出满嘴的金牙。",
   "正用手指挖鼻孔。",
   "两眼无神，似乎还没睡醒。",
});


void create()
{
// 此处用mapping 将会简单些 :)
   switch(random(16))
   {
     case 0:
        set_name(HIC"傻瓜相机"NOR, ({"papaya camera","camera"}));
        break;
     case 1 :
        set_name(HIC"莱卡Ｒ７"NOR, ({"Leica R7","camera"}));
        break;
     case 2 :
        set_name(HIC"尼康ＦＭ２"NOR, ({"Nikon FM2","camera"}));
        break;
     case 3 :
        set_name(HIC"美能达Ｘ７００"NOR, ({"Minolta X700","camera"}));
        break;
     case 4 :
        set_name(HIC"佳能ＡＬ１"NOR, ({"Canon AL1","camera"}));
        break;
     case 5 :
        set_name(HIC"奥林巴斯ＯＭ４"NOR, ({"Olympus OM4","camera"}));
        break;
     case 6 :
        set_name(HIC"潘太克斯Ｐ３０Ｎ"NOR, ({"Pentax P30N","camera"}));
        break;
     case 7 :
        set_name(HIC"美能达ＸＤ"NOR, ({"Minolta XD", "camera"}));
        break;
     case 8:
        set_name(HIC"尼康Ｆ５"NOR, ({"Nikon F5", "camera"}));
        break;
     case 9 :
        set_name(HIC"莱卡Ｍ１"NOR, ({"Leica M1", "camera"}));
        break;
     case 10 :
        set_name(HIC"尼康Ｆ９０"NOR, ({"Nikon F90", "camera"}));
        break;
     case 11 :
        set_name(HIC"美能达７００Ｓｉ"NOR, ({"Minolta 700Si","camera"}));
        break;
     case 12 :
        set_name(HIC"佳能ＥＯＳ１"NOR, ({"Canon EOS1","camera"}));
        break;
     case 13 :
        set_name(HIC"奥林巴斯ＬＳ１"NOR, ({"Olympus LS1","camera"}));
        break;
     case 14 :
        set_name(HIC"康太克斯ＲＴＳ３"NOR, ({"Contax RTS3","camera"}));
        break;
     case 15 :
        set_name(HIC"美能达９ｘｉ"NOR, ({"Minolta 9xi","camera"}));
        break;
   }
   set_weight(500);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("unit", "架");
     set("value", 100000);
     set("material", "steel");
     set("wield_msg", "$N急急忙忙地举起$n。\n");
     set("unwield_msg", "$N将手中的$n放回包里。\n");
   }
     init_hammer(10);
   setup();
}

void init()
{
     add_action("do_shoot","shoot");
}                                                        

int do_shoot(string arg)
{
   	object me,pic, env;
   	int i,EXP_NUM=sizeof(msg_expression);
   	mixed *inv;
   	string objname, str;

   	me = this_player();

      env = environment(me);
      str = objname = env->query("short");
      if( !env ) str = "照片上灰蒙蒙地一片，不知道是本来就是这样还是冲坏了。\n";
      else
      {
        str = sprintf( "%s的照片\n\n    %s%s\n",env->query("short"), env->query("long"),
             env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
          if( inv[i]==me || !me->visible(inv[i]) ) continue;
          if ( inv[i]->is_character() )
                 str += inv[i]->name(1)+msg_expression[random(EXP_NUM)] + "\n";          
            else str += YEL+"  [ " + inv[i]->name() +" ]\n" +NOR;
          }
       }

     	str += "\n" + me->query("name")+"摄于"+NATURE_D->game_time() + "。\n";
     	message_vision(HIW"$N举起$n"HIW"，轻轻按下了快门"HIY
          "\n    伴随着一道眩目的亮光和咔嚓一声响，人脏俱获你跑不掉啦。\n" NOR, me,this_object());

     	pic=new(__DIR__"photo");
     	pic->set_name( objname + "留影", ({ "photo" }) );
     	pic->set("long", str);

     	if( !pic->move(me) )
      pic->move(env);

   	return 1;
}

