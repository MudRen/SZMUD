#include <ansi.h> 
inherit NPC;

void create()
{
        set_name(HIY"����"NOR, ({ "da shou", "dashou"}));
        set("long", 

"������ȥ������֣���üŭĿ��������⡣�������µ�Ҳ�е㹦�� ��\n");
        set("gender", "����");
        set("age", 30+random(25));
 

   set("nickname",HIG"רְ����"NOR);
   set("attitude","heroism"); 
   set("str", 25); 
   set("dex", 25); 
   set("con", 30); 
   set("int", 25); 
   set_temp("apply/armor", 100);
   set_temp("apply/attack", 100);
   set_temp("apply/dodge", 100);    

   set_skill("strike", 200); 
   set_skill("claw", 200); 
   set_skill("zhaixinggong", 200); 
   set_skill("chousui-zhang", 200); 
   set_skill("sanyin-zhua", 200); 
   set_skill("force", 200); 
   set_skill("dodge", 200); 
   set_skill("parry", 200); 
   set_skill("literate", 300); 
   set_skill("staff",200); 
   set_skill("tianshan-zhang",200); 
   set_skill("throwing",200); 
   set_skill("feixing-shu",200);
   set_skill("poison",300); 
   set_skill("huagong-dafa",300); 

   map_skill("dodge", "zhaixinggong"); 
   map_skill("strike", "chousui-zhang"); 
   map_skill("claw", "sanyin-zhua"); 
   map_skill("force", "huagong-dafa"); 
   map_skill("staff","tianshan-zhang"); 

 prepare_skill("strike", "chousui-zhang");
 prepare_skill("claw", "sanyin-zhua"); 
 
   set("jiali",150); 
   set("jiajing",100);
   set("combat_exp", 1000000+1000*random(100)); 
   set("max_qi", 3300); 
   set("max_jing", 3200); 
   set("neili", 7200); 
   set("max_neili", 4000); 
   create_family("������",3,"����"); 

   set("shen_type", 0);
   setup();
   carry_object("/d/xingxiu/obj/yudi.c");
   carry_object("/clone/armor/tiejia")->wear();
}


