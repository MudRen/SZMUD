#include <ansi.h>
inherit NPC;
inherit F_DEALER;
void create()
{
            set_name("五姑", ({ "wu gu", "wu" }));
        set("shen_type", 0);
        set("age",31);
        set("gender", "女性");
        set("per",7);
        set("long",
                  "她就是和太冲的小老婆，只见她一张肿得犹如猪八戒一般，双眼深陷肉里，
几乎睁不开眼睛，喘气甚急，像是扯着风箱。\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("inquiry", ([
                "班淑娴" : "那个贱妇总有一天我会杀了她。\n",
                  "何太冲" : "他是我丈夫。\n",
                 "病" : "我也不知道是什么病。\n",
                   "灵脂兰" : "灵脂兰特别香，我在花园种了好多。\n",
        ]));
      
  setup();
          carry_object("/d/city/obj/pink_cloth")->wear();
}

