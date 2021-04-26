#include <ansi.h>

inherit F_CLEAN_UP;

string *color = ({
    RED, GRN, YEL, BLK, MAG, BLU, CYN, WHT, 
    HIR, HIG, HIY, HIB, HIM, HIC, HIW, });
string *color1 = ({
    RED, GRN, YEL, MAG, BLU, CYN, 
    });

void input_number(string arg);
void show_emote(string* arg,string text);

string *pic = ({ @TEXT
 .        *                  . . . .  .   .  + .
            "¹§ ºØ ĞÂ ìû" .   .  + [1;36m[5m¡î[2;37;0m[1;34m. . .
.                 |      .  .   .    .    . .
                  |     .    .    . +.    [1;36m[5m¡î[2;37;0m[1;34m  .
                 \|/            .       .   . .
        . .       V          .    * . . .  .  +   .
           +     [1;36m[5m¡î[2;37;0m[1;34m           .   .      +
                            .       . +  .+. .
  .                      .     . + [1;36m[5m¡î[2;37;0m[1;34m  . .     .      .
           .      .    .     . .   . . .
      [1;36m[5m¡î[2;37;0m[1;34m             .    . .  +    .  .           .
          .     .    .  +   . .  *  .       .
               . + .  .  .  .. +  .
.      .  .  .  [1;36m[5m¡î[2;37;0m[1;34m   .  [1;36m[5m¡î[2;37;0m[1;34m  . +..  .            *
 .      .   . .   .   .   . .  +   .    .            +
TEXT,
@TEXT
 .        *                  . . . .  .   .  + .
            "¹§ ºØ ĞÂ ìû" .   .  + [1;36m[5m¡î[2;37;0m[1;34m. . .
.                 |      .  .   .    .    . .
                  |     .    .    . +.    [1;36m[5m¡î[2;37;0m[1;34m  .
                 \|/            .       .   . .
        . .       V          .    * . . .  .  +   .
           +     [1;36m[5m¡î[2;37;0m[1;34m           .   .      +
                            .       . +  .+. .
  .                      .     . + [1;36m[5m¡î[2;37;0m[1;34m  . .     .      .
           .      .    .     . .   . . .
      [1;36m[5m¡î[2;37;0m[1;34m             .    . .  +    .  .           .
          .     .    .  +   . .  *  .       .
               . + .  .  .  .. +  .
.      .  .  .  [1;36m[5m¡î[2;37;0m[1;34m   .  [1;36m[5m¡î[2;37;0m[1;34m  . +..  .            *
 .      .   . .   .   .   . .  +   .    .            +
TEXT,
@TEXT
 .        *                  . . . .  .   .  + .
            "¹§ ºØ ĞÂ ìû" .   .  + [1;36m[5m¡î[2;37;0m[1;34m. . .
.                 |      .  .   .    .    . .
                  |     .    .    . +.    [1;36m[5m¡î[2;37;0m[1;34m  .
                 \|/            .       .   . .
        . .       V          .    * . . .  .  +   .
           +     [1;36m[5m¡î[2;37;0m[1;34m           .   .      +
                            .       . +  .+. .
  .                      .     . + [1;36m[5m¡î[2;37;0m[1;34m  . .     .      .
           .      .    .     . .   . . .
      [1;36m[5m¡î[2;37;0m[1;34m             .    . .  +    .  .           .
          .     .    .  +   . .  *  .       .
               . + .  .  .  .. +  .
.      .  .  .  [1;36m[5m¡î[2;37;0m[1;34m   .  [1;36m[5m¡î[2;37;0m[1;34m  . +..  .            *
 .      .   . .   .   .   . .  +   .    .            +
TEXT,
@TEXT
 .        *                  . . . .  .   .  + .
            "¹§ ºØ ĞÂ ìû" .   .  + [1;36m[5m¡î[2;37;0m[1;34m. . .
.                 |      .  .   .    .    . .
                  |     .    .    . +.    [1;36m[5m¡î[2;37;0m[1;34m  .
                 \|/            .       .   . .
        . .       V          .    * . . .  .  +   .
           +     [1;36m[5m¡î[2;37;0m[1;34m           .   .      +
                            .       . +  .+. .
  .                      .     . + [1;36m[5m¡î[2;37;0m[1;34m  . .     .      .
           .      .    .     . .   . . .
      [1;36m[5m¡î[2;37;0m[1;34m             .    . .  +    .  .           .
          .     .    .  +   . .  *  .       .
               . + .  .  .  .. +  .
.      .  .  .  [1;36m[5m¡î[2;37;0m[1;34m   .  [1;36m[5m¡î[2;37;0m[1;34m  . +..  .            *
 .      .   . .   .   .   . .  +   .    .            +
TEXT,
@TEXT
 .        *                  . . . .  .   .  + .
            "¹§ ºØ ĞÂ ìû" .   .  + [1;36m[5m¡î[2;37;0m[1;34m. . .
.                 |      .  .   .    .    . .
                  |     .    .    . +.    [1;36m[5m¡î[2;37;0m[1;34m  .
                 \|/            .       .   . .
        . .       V          .    * . . .  .  +   .
           +     [1;36m[5m¡î[2;37;0m[1;34m           .   .      +
                            .       . +  .+. .
  .                      .     . + [1;36m[5m¡î[2;37;0m[1;34m  . .     .      .
           .      .    .     . .   . . .
      [1;36m[5m¡î[2;37;0m[1;34m             .    . .  +    .  .           .
          .     .    .  +   . .  *  .       .
               . + .  .  .  .. +  .
.      .  .  .  [1;36m[5m¡î[2;37;0m[1;34m   .  [1;36m[5m¡î[2;37;0m[1;34m  . +..  .            *
 .      .   . .   .   .   . .  +   .    .            +
TEXT,
@TEXT
 .        *                  . . . .  .   .  + .
            "¹§ ºØ ĞÂ ìû" .   .  + [1;36m[5m¡î[2;37;0m[1;34m. . .
.                 |      .  .   .    .    . .
                  |     .    .    . +.    [1;36m[5m¡î[2;37;0m[1;34m  .
                 \|/            .       .   . .
        . .       V          .    * . . .  .  +   .
           +     [1;36m[5m¡î[2;37;0m[1;34m           .   .      +
                            .       . +  .+. .
  .                      .     . + [1;36m[5m¡î[2;37;0m[1;34m  . .     .      .
           .      .    .     . .   . . .
      [1;36m[5m¡î[2;37;0m[1;34m             .    . .  +    .  .           .
          .     .    .  +   . .  *  .       .
               . + .  .  .  .. +  .
.      .  .  .  [1;36m[5m¡î[2;37;0m[1;34m   .  [1;36m[5m¡î[2;37;0m[1;34m  . +..  .            *
 .      .   . .   .   .   . .  +   .    .            +
TEXT,
@TEXT
 .        *                  . . . .  .   .  + .
            "¹§ ºØ ĞÂ ìû" .   .  + [1;36m[5m¡î[2;37;0m[1;34m. . .
.                 |      .  .   .    .    . .
                  |     .    .    . +.    [1;36m[5m¡î[2;37;0m[1;34m  .
                 \|/            .       .   . .
        . .       V          .    * . . .  .  +   .
           +     [1;36m[5m¡î[2;37;0m[1;34m           .   .      +
                            .       . +  .+. .
  .                      .     . + [1;36m[5m¡î[2;37;0m[1;34m  . .     .      .
           .      .    .     . .   . . .
      [1;36m[5m¡î[2;37;0m[1;34m             .    . .  +    .  .           .
          .     .    .  +   . .  *  .       .
               . + .  .  .  .. +  .
.      .  .  .  [1;36m[5m¡î[2;37;0m[1;34m   .  [1;36m[5m¡î[2;37;0m[1;34m  . +..  .            *
 .      .   . .   .   .   . .  +   .    .            +
TEXT, });

int main(object me,string arg)
{
    object male, female, env;
    string id1, id2, name1, name2;

    env = environment(me);

    if( !arg || sscanf(arg, "%s with %s", id1, id2) != 2 )
        return notify_fail("Ö¸Áî¸ñÊ½£ºmbless MALE with FEMALE\n");

//    if( !objectp(male = get_object( id1 ) ) 
//        || !objectp(female = get_object ( id2 ) ) )
    if(!objectp(male = present(id1, environment(me))) ||
       !objectp(female = present(id2, environment(me))))
        return notify_fail("ÕâÀïÃ»ÓĞÕâÁ½¸öÈËÅ¶~~\n");

    if ( ! living( male ) || ! living (female) )
        return notify_fail("¿´Çå³şµã£¬ÄÇ²»ÊÇ»îµÄ¡£\n");
    if(( male->query("gender") != "ÄĞĞÔ" &&  male->query("gender") != "ĞÛĞÔ")
        ||(female->query("gender") != "Å®ĞÔ" &&female->query("gender")!="´ÆĞÔ"))
        return notify_fail("ÀÏĞÖ£¬²»Òª´íµãÔ§ÑìÅ¶~\n");

    name1 = male->query("name");
    name2 = female->query("name");

    if ((me->query("qi")<100) ||
        (me->query("jing")<100) ||
        (me->query("neili")<100))
        return notify_fail("ÄãÃ»ÓĞ¾«Éñ×£¸£ÈË¼ÒÁË !\n");
    me->set("qi",10);
    me->set("jing",10);
    me->set("neili",10);

//    if ( !me->query("env/score") )
    message_vision(HIY"\n\n\nÂíÄê¼ªÏé ¿ìÂí¼Ó±Ş Âíµ½³É¹¦£¡\n"NOR,
                me);
    call_out("show_picture", 2 + random( 3 ), name1, name2);
    return 1;
}

void show_picture(string name1, string name2)
{
    string str;
    str = HIW "\n\n\nÂíÄê¼ªÏé ¿ìÂí¼Ó±Ş Âíµ½³É¹¦£¡\n\n\n" NOR;
    message("marry",str, users());
    call_out("show_flower", 2, name1, name2);
}

void show_flower(string name1, string name2)
{
    string str;
    str = HIR"¡¾ ÉñÖİ ¡¿Î×Ê¦¹«»á¹§×£ËùÓĞÍæ¼Ò£º\n\n\n"NOR;
    str += color1[random(sizeof(color1))] + pic[random(sizeof(pic))] + NOR;
    str += YEL "\n\n\nÂíÄê¼ªÏé ¿ìÂí¼Ó±Ş Âíµ½³É¹¦£¡¡±\n\n\n";
    message("marry", str, users());
    if ( random( 2) )
        call_out( "show_flower",2 + random ( 3 ),name1,name2 );
}

