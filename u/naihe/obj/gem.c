  // 漂亮的宝石 ：）  ★/obj/gem.c
  // by naihe 奈何  2002-05-15
  /* 
  完全自己写的代码，一点都没有抄，哈哈哈  知识们已经记在脑子里了，哼，我测试了一晚上，
  试了不下20种手段来实现各个地方的随机创建，哼

  其实无论是文学，音乐，还是写程序，创意是最关键的一环；音乐技法是为了音乐本身服务的；
  文字本身是为文学服务的——同样，代码也是为了我们的程序而服务。没有好的气氛创意，再
  高的技巧，懂得再多的命令，知道再多的内部处理方式——写出来的东西，也许会是最有效率的，
  但——并不是最好的！！！

  日后多写些这些变化大的东西；而且是有气氛的东西吧。

  突然想起来！花店里的花不也是这样的吗！！！去看看它的代码才行！！！
  唉，一看起来就什么信心都没了，看人家的代码写得多简洁！哼  可惜那么好的代码技术糟蹋了，
  写的侠客行游戏那么烂，哼哼
  */

#include <ansi.h>
  inherit ITEM;

  string clname,smash,
  smash="not";

  int color=(random(5));


  void create()
  {
          if(color==0)
          {
                  set_name(HIG"绿宝石"NOR, ({"gem","baoshi","green gem"}));
                  clname="绿";
          }

          if(color==1)
          {
                  set_name(HIR"红宝石"NOR, ({"gem","baoshi","red gem"}));
                  clname="红";
          }

          if(color==2)
          {
                  set_name(HIB"蓝宝石"NOR, ({"gem","baoshi","blue gem"}));
                  clname="蓝";
          }

          if(color==3)
          {
                  set_name(HIM"紫宝石"NOR, ({"gem","baoshi","violet gem"}));
                  clname="紫";
          }

          if(color==4)
          {
                  set_name(HIC"天蓝宝石"NOR, ({"gem","baoshi","sapphire gem"}));
                  clname="天蓝";
          }

  // 上面的代码我实在是不想写成这样的，可惜我试了很多组合的方式，都不成功；
  // 就只能写成那么烦琐的啦……不过简单也好，稳定嘛  yeah~~~~~~~~

          switch(random(10))
          {
                  case 0:set("long","一颗"+clname+"色的宝石，泛着迷人的光芒。\n");
                  break;

                  case 1:set("long","这颗宝石色泽纯正，它的"+clname+"是完全的"+clname+"，让人爱不释手。\n");
                  break;

                  case 2:set("long","宝石里幽幽地散发着"+clname+"色的光芒。\n");
                  break;

                  case 3:set("long","这颗"+clname+"宝石圆圆的似个小球模样，煞是可爱。\n");
                  break;

                  case 4:set("long","这是一颗"+clname+"色的小宝石，里面似乎有些东西，打碎（smashup）它也许能够看得更清楚。\n");
                  smash="can";
                  break;

                  case 5:set("long",clname+"宝石里面似乎有些东西，但如果不打碎（smashup）它就无法看清。\n");
                  smash="can";
                  break;

                  case 6:set("long","宝石里散发着"+clname+"色的光芒，映入你的眼帘，让你产生无限遐思。\n");
                  break;

                  case 7:set("long","宝石里淡淡地散发着"+clname+"色的光芒。\n");
                  break;

                  case 8:set("long","你仔细地看了看，似乎"+clname+"宝石上面刻着几个小小的字：for spark 。\n");
                  break;

                  case 9:set("long","这是一颗暗淡无光的宝石，隐约看得似乎是"+clname+"色。\n");
                  break;
          }

          set_weight(30);
          set("unit", "颗");
          set("value", 0);

          setup();
  }

  void init()
  {
          if(smash=="can") add_action("do_smashup","smashup");
  }

  void del_me()
  {
          message_vision(""MAG"只见一阵轻烟冒起，小东西消失不见了。"NOR"\n",this_player());
          destruct(this_object());
  }


  int do_smashup(string arg)
  {
          object me=this_player();
          if(random(2)==1)
          {
                  message_vision(HIW"$N用力地把"+clname+"宝石往地上扔去！\n只见"+clname+"宝石一下子碎了开来，里面却什么都没有。"NOR"\n",me);
                  destruct(this_object());
                  return 1;
          }
          message_vision(HIW"$N用力地把"+clname+"宝石往地上扔去！\n只见"+clname+"宝石一下子碎了开来，原来里面有一片小东西。"NOR"\n",me);
          set_name(MAG"小东西"NOR, ({"things"}));
          set("long",""MAG"华山奈何宝藏室藏"NOR"\n");
          set("unit","片");
          set_weight(10);
          smash="not";
          call_out("del_me",5+random(10));
          this_object()->move(environment(me));
          return 1;
  }


