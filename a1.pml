typedef Mensagem = {
  pid uid;
  int cod
}
 
chan canal = [1] of {int}
chan outro = [8] of {Mensagem}
chan maisum = [0] of {int, byte}
