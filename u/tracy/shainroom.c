//by tracy
#include <ansi.h> 
inherit ROOM; 
void create()
{
     set("short", HIM"����С��"NOR);
     set("long", " 
��û���ݣ�һ�����������ζ����������������ܣ�����ɫ��ǽ���������\nһ�Ѱ�ɫ�ļ���.��ɫ��С��,���㲻������������һ��,�����,�����˶���\n�˽�ȥ.���������ݶ�����һ̧ͷ�Ϳ��������ϵ�����.Ϊʲô���������޵�?\n�ѵ����޻��ĵذ壿��������ʵ�������Ʋ������С����. \n   "HIM"    .    .   .          .    "NOR"                 
   "HIM"    .  ./~~~~~~~~~~~~'~.|  "NOR"   
   "HIM"     ,/,.,...........,.|  ."NOR" 
   "HIM"||  ..��#  ����  ��  ��| �� "NOR"
   "HIM"||    ��   ��        ��|'�� o  .. "NOR"  
   "HIM"||  �����������������������{�z�y�x "NOR"
");
     set("exits", ([ 
        "cs" : "/d/city/guangchang",
        "south" : __DIR__"workroom",
      ]));
     set("valid_startroom", 1);
     set("no_fight", 1);
     set("sleep_room", 1);
     set("no_death", 1);
     set("no_clean_up", 0);
     setup();
     
}
